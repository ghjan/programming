
#define GSTATUS1        (*(volatile unsigned int *)0x560000B0)
#define BUSY            1

#define NAND_SECTOR_SIZE_LP    2048
#define NAND_BLOCK_MASK_LP     (NAND_SECTOR_SIZE_LP - 1)

typedef unsigned int S3C24X0_REG32;//��ʵûʲô�ã�ֻΪ����ṹ��ÿ�

/* NAND FLASH (see S3C2440 manual chapter 6, www.100ask.net) */
typedef struct {
    S3C24X0_REG32   NFCONF;
    S3C24X0_REG32   NFCONT;
    S3C24X0_REG32   NFCMD;
    S3C24X0_REG32   NFADDR;
    S3C24X0_REG32   NFDATA;
    S3C24X0_REG32   NFMECCD0;
    S3C24X0_REG32   NFMECCD1;
    S3C24X0_REG32   NFSECCD;
    S3C24X0_REG32   NFSTAT;
    S3C24X0_REG32   NFESTAT0;
    S3C24X0_REG32   NFESTAT1;
    S3C24X0_REG32   NFMECC0;
    S3C24X0_REG32   NFMECC1;
    S3C24X0_REG32   NFSECC;
    S3C24X0_REG32   NFSBLK;
    S3C24X0_REG32   NFEBLK;
} S3C2440_NAND;

//����ṹ�����˵�ǳ����ߣ�ֻ��Ϊ���Ժ��Ķ����Ѷȴ������̵�
typedef struct {
    void (*nand_reset)(void);
    void (*wait_idle)(void);
    void (*nand_select_chip)(void);
    void (*nand_deselect_chip)(void);
    void (*write_cmd)(int cmd);
    void (*write_addr)(unsigned int addr);
    unsigned char (*read_data)(void);
}t_nand_chip;
//����s3c2440_nand����ṹ��ĺô������� ֻ��Ҫ�������ṹ������һ�μĴ����ĵ�ַ
// ��һ������CFCONF����0x4e000000 �ڶ������� �� + 4 unsigned int �� intһ������4�ֽ� 
static S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;

// ���ṹ�嶨��һ������
static t_nand_chip nand_chip;

//���ⲿ���õĺ��� �� head.S ��  ����
void nand_init(void);
void nand_read(unsigned char *buf, unsigned long start_addr, int size);

/* NAND Flash�����������, ���ǽ�����S3C2410��S3C2440����Ӧ���� */
static void nand_reset(void);
static void wait_idle(void);
static void nand_select_chip(void);
static void nand_deselect_chip(void);
static void write_cmd(int cmd);
static void write_addr(unsigned int addr);
static unsigned char read_data(void);

/* S3C2440��NAND Flash������ */
static void s3c2440_nand_reset(void);
static void s3c2440_wait_idle(void);
static void s3c2440_nand_select_chip(void);
static void s3c2440_nand_deselect_chip(void);
static void s3c2440_write_cmd(int cmd);
static void s3c2440_write_addr(unsigned int addr);
static unsigned char s3c2440_read_data(void);

/* S3C2440��NAND Flash�������� */

/* ��λ */
static void s3c2440_nand_reset(void)
{
    s3c2440_nand_select_chip();
    s3c2440_write_cmd(0xff);  // ��λ���0xff��
    s3c2440_wait_idle();
    s3c2440_nand_deselect_chip();
}

/* �ȴ�NAND Flash���� */
static void s3c2440_wait_idle(void)
{
    volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFSTAT;
    while(!(*p & BUSY));// ��nand æ��æ  1 ���ǲ�æ ��������ִ�� 0����æ һֱѭ��
}

/* ����Ƭѡ�ź� */
static void s3c2440_nand_select_chip(void)
{
    s3c2440nand->NFCONT &= ~(1<<1);// Ϊ 0 ���ǿ���Ƭѡ
}

/* ȡ��Ƭѡ�ź� */
static void s3c2440_nand_deselect_chip(void)
{
    s3c2440nand->NFCONT |= (1<<1); //Ϊ 1 ���ǹر�Ƭѡ
}

/* �������� */
// cmd ��������ʹ����� ������
static void s3c2440_write_cmd(int cmd)
{
    volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFCMD;
    *p = cmd;
}

/* ������ַ */
static void s3c2440_write_addr(unsigned int addr)
{
    volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFADDR;

	// nand ��2048��block��11����ַ�ߣ�  ÿ��block �� 64 page��6����ÿ�� page ��2k+64 bytes
	// ���涨���page ���� ҳ�ľ���ֵ (��11+6����ַ��ȷ���� ���ĸ�block �е���һҳ)
	//��סֻ��Ҫ֪���� �ĸ����ĸ�ҳ������ҳ�ľ���ֵ�� �Ϳ�����
// NAND flash ����ҳΪ��λ��д���� ���Կ�Ϊ��λ�������ݣ����Զ���ʱ����Ҫ����һҳ�еĵ�ַ����Ϊ��һҳҪȫ�������ʵ�
// ����ʱ���Բ��ù� ����ռ䣨64�ֽڣ� ��Ϊ��ȡ��ַ�����������������ȥ
	int page = addr / NAND_SECTOR_SIZE_LP;// NAND_SECTOR_SIZE_LP����ҳ�Ĵ�С
	
	// ȷ������һ���˾Ϳ�ʼ����ַ��
	// mini2440 nand flash ���ͺ��� K9F2G08U0B  һ����29����ַ��
	// �� nand ��ԭ��ͼ����֪�� ��Ҫ 5�����ڲ��ܶ��꣨ÿ�����ڶ�8λ��ֻ��8��IO�ӿ��ߣ�Ҳ�����ֽڣ�
	// ��Ϊ����ҳΪ��λ��д���� ���� ҳ��A0--A11��ַ�߲��ù�������Ҫ���꣩����Ϊ0 �ͺ�
	// ����������Ҫ����nand    �����׵�ַλ���ĸ� ҳ��ҳ�ϸ��ĸ��ط����ù�
	*p =0;			/* Column Address A0~A7 */	
	
	*p =0; 	/* Column Address A8~A11 */// �У�column����ַ ����ҳ�ڵĵ�ַ
	
	*p = page & 0xff;			/* Row Address A12~A19 */// ҳ��ַҲ���У�Row����ַ
	
	*p = (page >> 8) & 0xff;	/* Row Address A20~A27 */
	
	*p = (page >> 16) & 0x1;	/* Row Address A28 ֻҪ����һ����ַ���оͺ� */
}

/* ��ȡ���� */
static unsigned char s3c2440_read_data(void)
{
	// �� NFDATA ��ֱ�Ӷ�ȡλ�ڸõ�ַ�е����� 
    volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFDATA;
    return *p;
}


/* �ڵ�һ��ʹ��NAND Flashǰ����λһ��NAND Flash */
static void nand_reset(void)
{
    nand_chip.nand_reset();
}

static void wait_idle(void)
{
    nand_chip.wait_idle();
}

static void nand_select_chip(void)
{
    int i;
    nand_chip.nand_select_chip();
    for(i=0; i<10; i++);
}

static void nand_deselect_chip(void)
{
    nand_chip.nand_deselect_chip();
}

static void write_cmd(int cmd)
{
    nand_chip.write_cmd(cmd);
}
static void write_addr(unsigned int addr)
{
    nand_chip.write_addr(addr);
}

static unsigned char read_data(void)
{
    return nand_chip.read_data();
}


/* ��ʼ��NAND Flash */
void nand_init(void)
{
#define TACLS   0
#define TWRPH0  3
#define TWRPH1  0

        nand_chip.nand_reset         = s3c2440_nand_reset;
        nand_chip.wait_idle          = s3c2440_wait_idle;
        nand_chip.nand_select_chip   = s3c2440_nand_select_chip;
        nand_chip.nand_deselect_chip = s3c2440_nand_deselect_chip;
        nand_chip.write_cmd          = s3c2440_write_cmd;
        nand_chip.write_addr         = s3c2440_write_addr;
        nand_chip.read_data          = s3c2440_read_data;

		/* ����ʱ�� */
        s3c2440nand->NFCONF = (TACLS<<12)|(TWRPH0<<8)|(TWRPH1<<4);
        /* ʹ��NAND Flash������, ��ʼ��ECC, ��ֹƬѡ */
        s3c2440nand->NFCONT = (1<<4)|(1<<1)|(1<<0);
    
    /* ��λNAND Flash */
    nand_reset();
}

/* ������ */
void nand_read(unsigned char *buf, unsigned long start_addr, int size)
{
    int i, j;
    
    if ((start_addr & NAND_BLOCK_MASK_LP) || (size & NAND_BLOCK_MASK_LP)) {
        return ;    /* ��ַ�򳤶Ȳ����� */
    }
//��Ϊnand�Ķ�ȡ��С��λ��Page��������ʼ��ַ������Page���׵�ַ�����ȱ�����ҳ��������
    /* ѡ��оƬ */
    nand_select_chip();

    for(i=start_addr; i < (start_addr + size);) {
      /* ����READ0���� */
      write_cmd(0);

      /* Write Address */
      write_addr(i);
	  
	  //��һ������Ҫ ��nand ����һ���� plane(�洢��)�Ķ���
	  // ������֪K9F2G08U0BӦ���������� plane���������Two-plane copy-back program��˫��Ҷ���
	  // ÿ�� plane=2048+64 byteҳ�Ĵ���  ÿ��plane ���� 1024 block
	 // ��һ��ֻ�ܶ� һ�������  �ڶ��ξ��Ƕ�ʣ�µĲ����(so Ҫ�������ڲ��ܶ�д��)
	  write_cmd(0x30);	//0x30���ǵڶ������ڶ��� ������
			
      wait_idle();// ��nand æ��æ Ҳ���Ƕ�������û��

	  // ����ͽ���copy 
	  // �� ���� �� ��ַ�ϵ�����  ȫ��������  buf ��ָ��ĵ�ַ��ȥ
	  // ÿ��ֻ��ȡһҳ������ 2K
	  // �����Ƕ���ַ ���Ƕ�����  ������һҳ�ϲ�����
      for(j=0; j < NAND_SECTOR_SIZE_LP; j++, i++) {
          *buf = read_data();
          buf++;
      }
	  // ���û�п�����  ������һҳ�Ĵ�С  ��ʼ��ַҲ�䵽����һ��ҳ��ַ
	  // �����������   ��Ҳ����Ϊʲô i ҲҪ���� buf�����Ƶ�Ŀ�ĵ�ַ���� 1 ԭ��
    }

    /* ȡ��Ƭѡ�ź� */
    nand_deselect_chip();
    
    return ;
}

