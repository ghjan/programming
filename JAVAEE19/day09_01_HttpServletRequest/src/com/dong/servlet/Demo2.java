package com.dong.servlet;

import java.io.IOException;
import java.util.Enumeration;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Demo2 extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// ��ȡ�������Ϣ(request);

		// ��ȡ��Ϣͷ(request);

		// ������name����Ϣͷ
		Enumeration headers = request.getHeaders("accept-language");
		while (headers.hasMoreElements()) {
			String e = (String) headers.nextElement();
			System.out.println(e + ":" + request.getHeader(e));
		}
	}

	private void ��ȡ��Ϣͷ(HttpServletRequest request) {
		// ��ȡ������Ϣͷ
		Enumeration names = request.getHeaderNames();
		while (names.hasMoreElements()) {
			String name = (String) names.nextElement();
			System.out.println(name + "����" + request.getHeader(name));// request.getHeader(name)�ǻ�ȡĳ����Ϣͷ������
		}
	}

	private void ��ȡ�������Ϣ(HttpServletRequest request) {
		/*
		 * һ��ʲô��User-Agent User-Agent��HttpЭ���е�һ���֣�����ͷ�����ɲ��֣�User AgentҲ���UA��
		 * �����UA �ִ��ı�׼��ʽΪ�� �������ʶ (����ϵͳ��ʶ; ���ܵȼ���ʶ; ���������) ��Ⱦ�����ʶ �汾��Ϣ
		 */
		String header = request.getHeader("User-Agent");
		System.out.println(header);

		if (header.toLowerCase().contains("msie")) {
			System.out.println("�����õ��������IE");
		} else if (header.toLowerCase().contains("chrome")) {
			System.out.println("�����õ��ǹȸ������");
		}
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
