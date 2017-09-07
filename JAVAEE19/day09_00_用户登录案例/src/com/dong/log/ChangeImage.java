package com.dong.log;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

import javax.imageio.ImageIO;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import cn.dsna.util.images.ValidateCode;


public class ChangeImage extends HttpServlet {

	//ValidateCode.jar �� ����ͼ�񣬱��˶���װ����
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		//���߸����������ʹ�û���(������index��jsp��ֱ�ӿ���������)
		response.setHeader("pragma", "no-cache");
		response.setHeader("cache-control", "no-cache");
		response.setHeader("expires", "0");
		
		ValidateCode vc = new ValidateCode(200, 50, 4, 20);
		//ValidateCode vc = new ValidateCode(110, 25, 4, 9);
		vc.write(response.getOutputStream());
		
		//��ȡ��֤���ֵ
		String code = vc.getCode();
		System.out.println(code);
	}

	//�Լ�д��֤��ͼƬ
	private void myImage(HttpServletResponse response) throws IOException {
		//���ڴ��д���һ��ͼ�����
		int width = 200;
		int height = 100;
		BufferedImage img = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
		//����һ������
		Graphics g = img.getGraphics();
		//��ͼƬһ������ɫ
		g.setColor(Color.GRAY);
		g.fillRect(0, 0, width, height);
		g.setColor(Color.PINK);
		g.fillRect(10, 10, width-20, height-20);
		
		//�����ı���ʽ
		g.setColor(Color.BLUE);
		g.setFont(new Font("����", Font.BOLD|Font.ITALIC, 70));//bold	�Ӵ�	italic б�� 
		
		//��ͼƬ����ı�
		Random random = new Random();
		for (int i = 0; i < 4; i++) {
			g.drawString(random.nextInt(10)+"", 15+40*i, 75);
		}
		
		//��Ӹ�����
		for (int i = 0; i < 20; i++) {
			g.drawLine(random.nextInt(width), random.nextInt(height), random.nextInt(width), random.nextInt(height));
		}
		
		//��ͼƬ���������ķ�ʽ����Ŀͻ���
		ImageIO.write(img, "png", response.getOutputStream());
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
