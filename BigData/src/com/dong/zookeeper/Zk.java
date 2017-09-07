package com.dong.zookeeper;

import java.io.IOException;
import java.util.List;

import org.apache.zookeeper.CreateMode;
import org.apache.zookeeper.KeeperException;
import org.apache.zookeeper.WatchedEvent;
import org.apache.zookeeper.Watcher;
import org.apache.zookeeper.ZooDefs.Ids;
import org.apache.zookeeper.ZooKeeper;
import org.apache.zookeeper.data.Stat;
import org.junit.Before;
import org.junit.Test;
/*
 * 2�����Run as --->Junit Test�����к���@Testע�͵ķ����ǣ���ô����ע�ⷽ��������ִ�У�������ִ��˳���ǣ�
     @BeforeClass ��@Before��@Test��@After��@AfterClass
 * */
public class Zk {
	/*
	 * 2181���ͷ��˶˿ڣ���/zookeeper-3.4.5/conf/zoo.cfg�п����޸�
	 * Ҫ��mini1������֣���Ҫ��C:\windows\system32\drivers\etc\hosts �����
	 * ���ֲ�����"mini1:2181,mini2:2181,mini3:2181";���������ã��ҷ��������Ӳ��ϣ���ֻ������һ��
	 */
	//private static final String connectString = "mini1:2181,mini2:2181,mini3:2181";
	private static final String connectString = "mini1:2181";
	private static final int sessionTimeout = 2000;
	static ZooKeeper zkClient = null;
	@Before
	public void init() throws IOException{
		zkClient = new ZooKeeper(connectString,sessionTimeout,new Watcher(){
			@Override
			public void process(WatchedEvent event) {
				// ÿ�νڵ㱻���ӣ�ɾ��������ִ������ص�������   ���Ǹ�����ڵ��data�ǲ��ᴥ����
				System.out.println(event.getType() + "---" + event.getPath());
				try {
					zkClient.getChildren("/", true);
				} catch (Exception e) {
				}
			}
		});
	}
	// �������ݽڵ㵽zk��
	@Test
	public void Create() throws KeeperException, InterruptedException{
		// ����1��Ҫ�����Ľڵ��·�� ����2���ڵ������ ����3���ڵ��Ȩ�� ����4���ڵ������
		//�ϴ������ݿ������κ����ͣ�����Ҫת��byte[]
		String nodeCreate = zkClient.create("/eclipse", "hello_zk".getBytes(),  Ids.OPEN_ACL_UNSAFE, CreateMode.PERSISTENT);
	}
	//�ж�znode�Ƿ����
	@Test	
	public void testExist() throws Exception{
		Stat stat = zkClient.exists("/eclipse", false);
		System.out.println(stat==null?"not exist":"exist");
	}
	// ��ȡ�ӽڵ�
	@Test
	public void getChildren() throws Exception {
		List<String> children = zkClient.getChildren("/", true);
		for (String child : children) {
			System.out.println(child);
		}
		Thread.sleep(Long.MAX_VALUE);
	}
	//��ȡznode������
	@Test
	public void getData() throws KeeperException, InterruptedException{
		byte[] data = zkClient.getData("/eclipse", false, null);
		System.out.println(new String(data));
	}
	//ɾ��znode
	@Test
	public void deleteZnode() throws Exception {
		//����2��ָ��Ҫɾ���İ汾��-1��ʾɾ�����а汾
		zkClient.delete("/eclipse", -1);
	}
	//�޸�znode��Ϣ
	@Test
	public void setData() throws Exception {
		zkClient.setData("/root/dong", "imissyou angelababy".getBytes(), -1);
	}
	
	
	
	
	
	
	public static void main(String[] args) throws IOException, KeeperException, InterruptedException {
		 ZooKeeper zk = new ZooKeeper("192.168.56.10:2181", 3000, null);  
	        System.out.println("=========�����ڵ�===========");  
	        if(zk.exists("/test", false) == null)  
	        {  
	            zk.create("/test", "znode1".getBytes(), Ids.OPEN_ACL_UNSAFE, CreateMode.PERSISTENT);  //create�����ڵ�
	        }  
	        System.out.println("=============�鿴�ڵ��Ƿ�װ�ɹ�===============");  
	        System.out.println(new String(zk.getData("/test", false, null)));  						//  getData�鿴�ڵ�����
	          
	        System.out.println("=========�޸Ľڵ������==========");  
	        zk.setData("/test", "zNode2".getBytes(), -1);  											//  �޸Ľڵ�����
	        System.out.println("========�鿴�޸ĵĽڵ��Ƿ�ɹ�=========");  
	        System.out.println(new String(zk.getData("/test", false, null)));  
	          
	        System.out.println("=======ɾ���ڵ�==========");  
	        zk.delete("/test", -1);  																// delete ɾ���ڵ�
	        System.out.println("==========�鿴�ڵ��Ƿ�ɾ��============");  
	        System.out.println("�ڵ�״̬��" + zk.exists("/test", false));  								// �жϽڵ��Ƿ����exists
	        zk.close();  
	}
}

