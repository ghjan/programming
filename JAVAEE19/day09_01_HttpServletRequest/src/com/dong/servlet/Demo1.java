package com.dong.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Demo1 extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
//		getMethod(); �������ʽ
//		***getRequestURL();���ؿͻ��˷�������ʱ������URL��
//		***getRequestURI(); �����������е���Դ�����֡�
//		*****getContextPath(); ��ǰӦ�õ�����Ŀ¼ /day09_01_HttpServletRequest
//		getQueryString() ; �����������еĲ������֡�
		
		System.out.println(request.getMethod());		// 	GET
		System.out.println(request.getRequestURL());	//http://localhost:8080/day09_01_HttpServletRequest/servlet/Demo1
		System.out.println(request.getRequestURI());	// /day09_01_HttpServletRequest/servlet/Demo1
		System.out.println(request.getContextPath());	// /day09_01_HttpServletRequest
		System.out.println(request.getQueryString());	// �������������ʲô�ͷ���ʲô �������?name=dong �ͷ���name=dong
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
