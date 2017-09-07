package com.dong.servlet;

import java.io.FileInputStream;
import java.io.IOException;
import java.net.URLEncoder;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

//ʵ��ͼƬ����
public class ServletDemo3 extends HttpServlet {

	/*public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		//��ȡͼƬ����·��
		String path = getServletContext().getRealPath("/WEB-INF/classes/��ɯ.jpg");
		//��ȡͼƬ��������
		FileInputStream fis = new FileInputStream(path);
		//�����ֽ������
		ServletOutputStream os = response.getOutputStream();
		
		//���п���
		int len = 0;
		byte[] b = new byte[1024];
		while((len = fis.read(b))!=-1){
			os.write(b, 0, len);
		}
		//���Բ��ùأ����������Թر�
		os.close();
		fis.close();
		//�������Ļ�����ֱ������ҳ������ʾͼƬ
	}*/
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		//��ȡͼƬ����·��
		String path = getServletContext().getRealPath("/WEB-INF/classes/��ɯ.jpg");
		//��ȡͼƬ��������
		FileInputStream fis = new FileInputStream(path);
		//�����ֽ������
		ServletOutputStream os = response.getOutputStream();
		
		//System.out.println(path);//D:\tomcat-7.0.52\webapps\day09_00_HttpServletResponse\WEB-INF\classes\��ɯ.jpg
		//���Ҫ���ص��ļ���
		String filename = path.substring(path.lastIndexOf("\\")+1);//ע��windows����  \  �����ļ��зָ�
		//�����ļ����ı���
		String filename2 = URLEncoder.encode(filename, "UTF-8");
		//���߿ͷ�������һ�����صĶ���
		response.setHeader("content-disposition", "attachment;filename="+filename2);
		response.setHeader("content-type", "image/jpeg");
		
		//���п���
		int len = 0;
		byte[] b = new byte[1024];
		while((len = fis.read(b))!=-1){
			os.write(b, 0, len);
		}
		os.close();
		fis.close();
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
