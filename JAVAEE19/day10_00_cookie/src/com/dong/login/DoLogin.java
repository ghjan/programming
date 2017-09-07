package com.dong.login;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
//�޸��˺ü��Σ��Ƚ�������
public class DoLogin extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setContentType("text/html;charset=UTF-8");

		// ��ȡ������
		String username = request.getParameter("username");
		String pwd = request.getParameter("pwd");
		String remName = request.getParameter("remName");
		String remPwd = request.getParameter("remPwd");
		//��������Ǻ������ϵģ���Ϊ����α������˺����룬���Կ�����ַ��ֱ�Ӹ�����������û���������ֵ�¼ʧ�ܵ����
		if(username==null && pwd ==null){
			// �õ��ͻ��˱����Cookie���� һ��ʼ���ж��Ƿ���cookies
			Cookie[] cookies = request.getCookies();
			for (int i = 0; cookies != null && i < cookies.length; i++) {
				if ("name".equals(cookies[i].getName())) {// �ж��Ƿ񱣴���û���
					username = cookies[i].getValue();
					remName = "checked='checked'";
					continue;
				}
				if (!"".equals(username) && "pwd".equals(cookies[i].getName())) {// ����û�����Ϊ�գ���ô��֤�Ƿ�֮ǰ���������
					pwd = cookies[i].getValue();
					remPwd = "checked='checked'";
				}
			}
		}
		
		// ����ҵ���߼�
		// �ַ�ת��
		Cookie cName = new Cookie("name", username);
		Cookie cPwd = new Cookie("pwd", pwd);
		PrintWriter w = response.getWriter();
		if ("dong".equals(username) && "123".equals(pwd)) {// ��¼�ɹ�
			if (remPwd == null) {
				cPwd.setMaxAge(0);
			} else {
				cPwd.setMaxAge(Integer.MAX_VALUE);
			}
			// Ҫ���ж����룬��Ϊ����û���û�б����棬��ô����϶��ᱻɾ����Ϊ�˱��⣬����ѡ�����û�������ѡ�����������
			if (remName == null) {// �п�����ε�¼��ʱ��û�е� �����û���
				cName.setMaxAge(0);// ɾ�� name cookie
				cPwd.setMaxAge(0);
			} else {
				cName.setMaxAge(Integer.MAX_VALUE);// MAX_VALUE = 2147483647
													// [0x7fffffff]
			}
			response.addCookie(cName);
			response.addCookie(cPwd);
			w.write("��¼�ɹ�");
		} else {
			w.write("��¼ʧ�ܣ�");
			cPwd.setMaxAge(0);//��¼ʧ���������
			response.addCookie(cPwd);
			// ����2���������µ�¼
			response.setHeader("refresh", "2;url=" + request.getContextPath()
					+ "/servlet/Login");
		}
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
