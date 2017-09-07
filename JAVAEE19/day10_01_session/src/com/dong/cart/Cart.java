package com.dong.cart;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.dong.DbUtil.Utils;
import com.dong.entity.Beauty;

public class Cart extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter out = response.getWriter();
		out.print("����վ��������ü<br><br>");
//1������ݿ�����ȡ��һЩMM����ʾ����
		Map<String, Beauty> beauties = Utils.findAllBeauty();//��ȡMM����
		for (Map.Entry<String, Beauty> b : beauties.entrySet()) {
//2�������Ӿ����ǹ����ˣ�ת��AddCart����
			out.print("<a href='"+request.getContextPath()+"/servlet/AddCart?id="+b.getKey()+"'>"+b.getValue().getName()+"<br>���ۣ�"+b.getValue().getPrice()+"</a><br><br>");
		
			//��������ôд�������ǣ��ڽ���cookie��ʱ�򣬿�����url�д���session��id���Ͳ���cookie���д���
//			String url = request.getContextPath()+"/servlet/addCart?id="+book.getKey();
//			out.print("<a href='"+response.encodeURL(url)+"' >"+book.getValue().getName()+"</a><br/>");
		}
//3��ת���鿴���ﳵ
		out.print("<hr><a href='"+request.getContextPath()+"/servlet/ShowCart'>�鿴���ﳵ</a>");
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
