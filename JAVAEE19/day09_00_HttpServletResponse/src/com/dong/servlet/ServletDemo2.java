package com.dong.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ServletDemo2 extends HttpServlet {
/*	PrintWriter���ַ�Ϊ��λ��֧�ֺ��֣�
	OutputStreamWriter���ֽ�Ϊ��λ����֧�ֺ��֣�

	������Ҫ���ö��Ķ�������PrintWriter���ַ�
	����������Ķ�������OutputStreamWriter��������*/	
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html;charset=UTF-8");

		ServletOutputStream sos = response.getOutputStream();
		//sos.write("���123".getBytes());// getBytesĬ�ϱ���Ϊ���ر��루����gbk��
		sos.write("���123".getBytes("UTF-8"));//ʹ��UTF-8
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
