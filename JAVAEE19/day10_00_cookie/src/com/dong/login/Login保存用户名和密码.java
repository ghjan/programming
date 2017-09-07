package com.dong.login;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Login�����û��������� extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setContentType("text/html;charset=UTF-8");
		
		String username = "";
		String password = "";
		String checkedN = "";
		String checkedP = "";
		//�õ��ͻ��˱����Cookie����					һ��ʼ���ж��Ƿ���cookies
		Cookie[] cookies = request.getCookies();
		for (int i = 0; cookies!=null && i <  cookies.length; i++) {
			if("name".equals(cookies[i].getName())){//�ж��Ƿ񱣴���û���
				username = cookies[i].getValue();
				checkedN = "checked='checked'";
				continue;
			}
			if(!"".equals(username) && "pwd".equals(cookies[i].getName())){//����û�����Ϊ�գ���ô��֤�Ƿ�֮ǰ���������
				password = cookies[i].getValue();
				checkedP = "checked='checked'";
			}
		}
		
		//��servlet����һ����
		PrintWriter w = response.getWriter();
		w.write("<form action='"+request.getContextPath()+"/servlet/DoLogin' method='post'>");//�ύ������ת��DoLogin��
		w.write("<p>&nbsp;&nbsp;&nbsp;�˺ŵ�¼<br></p>");
		w.write("<input type='text' name=username value="+username+"><br>");
		w.write("<input type='password' name=pwd value="+password+"><br>");
		w.write("<input type='checkbox' name=remName "+checkedN+">��ס�û���");//remember
		w.write("<input type='checkbox' name=remPwd "+checkedP+">��ס����<br>");
		w.write("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type='submit' valur='��¼'>");
		w.write("<form/>");
		
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
