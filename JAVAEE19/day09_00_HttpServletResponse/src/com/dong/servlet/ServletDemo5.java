package com.dong.servlet;

import java.io.IOException;
import java.util.Random;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ServletDemo5 extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		//ͳһ����
		response.setContentType("text/html;charset=UTF-8");
		/*//response.setHeader("refresh", "1");//1sˢ��һ��
		response.setIntHeader("refresh", 1);//������һ��Ч��
		Random r = new Random();
		response.getWriter().write(r.nextInt(100)+"");*/
		
		//����3��������ҳ
		response.getWriter().write("ע��ɹ���3���������ҳ");
		response.setHeader("refresh", "3;url=http://www.baidu.com");
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
