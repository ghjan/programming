package com.dong.web.servlet;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.apache.commons.beanutils.BeanUtils;

import com.dong.domain.User;
import com.dong.service.UserService;
import com.dong.service.impl.UserServiceImpl;


public class LoginServlet extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		//��ȡ������
		User user = new User();
		try {
			//��Ϊ����ֻ��Ҫ��֤�˺����룬���Բ���ҪConverת���ַ���Ϊʱ��
			BeanUtils.populate(user, request.getParameterMap());//�����ݷŵ� user��
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} catch (InvocationTargetException e) {
			e.printStackTrace();
		}
		UserServiceImpl us = new UserServiceImpl();
		
		if(us.login(user) != null){
			//�ַ�ת��
			request.getSession().setAttribute("u", user);//���浽session��
			request.getRequestDispatcher("/index.jsp").forward(request, response);
		} else{
			request.setAttribute("u", user);//��ֻ����ʾһ��
			request.getRequestDispatcher("/login.jsp").forward(request, response);
		}
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
