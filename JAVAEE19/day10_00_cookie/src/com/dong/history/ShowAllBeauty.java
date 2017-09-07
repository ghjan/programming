package com.dong.history;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.dong.DbUtil.Utils;
import com.dong.entity.Beauty;

public class ShowAllBeauty extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter w = response.getWriter();
		w.print("<p>����վ���۸�����Ů</p><br>");
//0������ݿ��л�ȡ���ݣ�����ӡ
		Map<String, Beauty> all = Utils.findAllBeauty();
		for (Map.Entry<String, Beauty> b : all.entrySet()) {
			w.print("<a href='" + request.getContextPath()
					+ "/servlet/ShowOneBeauty?id=" + b.getKey()
					+ "' target='_blank'>" + b.getValue().getName() + "<br>����:"
					+ b.getValue().getPrice() + "</a><br><br>");
		}
		
		w.print("<hr>����������:<br><br>");
		//��ȡcookie
		Cookie[] cookies = request.getCookies();
//1���ҵ���������Ҫ��cookie
		for (int i = 0; cookies!=null && i < cookies.length; i++) {
			if("history".equals(cookies[i].getName())){
				String value = cookies[i].getValue();
				String[] split = value.split("-");//�������Ǽ������ݵı�ţ���   1-2-3
//2������������cookie�еļ���id�š�����cookie��ֻ�ܴ���ַ���
				for (int j = 0; j < split.length; j++) {//�����⼸����
					Beauty beauty = Utils.findBeauty(split[j]);
					w.print(beauty.getName()+"<br>");
				}
			}
		}
		
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
