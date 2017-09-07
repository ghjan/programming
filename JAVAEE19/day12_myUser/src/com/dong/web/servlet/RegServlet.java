package com.dong.web.servlet;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.commons.beanutils.ConvertUtils;
import org.apache.commons.beanutils.Converter;
import org.apache.commons.beanutils.locale.converters.DateLocaleConverter;

import com.dong.domain.User;
import com.dong.domain.UserForm;
import com.dong.service.UserService;
import com.dong.service.impl.UserServiceImpl;

public class RegServlet extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setContentType("text/html;charset=UTF-8");
		
		//��ȡ������ǰ�ȣ�����һ��
		UserForm userForm = new UserForm();
		try {
			BeanUtils.populate(userForm, request.getParameterMap());
		} catch (Exception e1) {
			e1.printStackTrace();
		}
		
		if(!userForm.validate()){// ���map�в�Ϊ�գ�˵���д�����Ϣ
			request.setAttribute("uf", userForm);
			request.getRequestDispatcher("/reg.jsp").forward(request, response);
			return;
		}
		
		//��ȡ������
		User user = new User();
		try {
			//������һЩ key-value ��ֵ������ hashmap��ӳ�䵽 bean �е����ԡ�
			//�ȶ���form�����ݵ�Info����(��Ȼ��Ҫ��дһ��bean,���bean�а���form���и������������)
			//����> populateBean(info, request.getParameterMap());���Ƚ�request����תΪMap���ͣ�
			//����>BeanUtils.populate(info, propertyMap);�����ð��з���ӳ�䣩
			
			//�ı�String����ΪDate����
			/*ConvertUtils.register(new Converter() {
				public Object convert(Class type, Object value) {
					Date date1 = null;
					if(value instanceof String){
						String date = (String)value;
						SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
						try {
							date1 = sdf.parse(date);
						} catch (ParseException e) {
							e.printStackTrace();
						}
					}
					return date1;
				}
			}, Date.class);*///������һ��λ�������������һ�н��
			ConvertUtils.register(new DateLocaleConverter(), Date.class);//����ת��Ϊ�ַ���
			ConvertUtils.register(new DateLocaleConverter(), Date.class);//������ܰ����ڼ��뵽����
			//����ConvertUtilsҲ�С���ֻ��û�����ڶ��ѣ�������user.setBirthday(request.getParameter(birthday));������������Ҳ��
			BeanUtils.populate(user, request.getParameterMap());
		} catch (Exception e) {
			e.printStackTrace();
			System.out.println("BeanUtils.populate(user, request.getParameterMap())����");
		}
		
		//����ҵ���߼�
		UserService us = new UserServiceImpl();
		us.register(user);
		
		//�ַ�ת��
		response.getWriter().write("ע��ɹ�,1s��������ҳ");
		response.setHeader("refresh", "1,url="+request.getContextPath()+"/index.jsp");
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
