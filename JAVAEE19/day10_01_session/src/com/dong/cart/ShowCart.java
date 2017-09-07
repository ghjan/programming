package com.dong.cart;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.dong.entity.Beauty;

public class ShowCart extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter out = response.getWriter();
//3.1��鿴�Ƿ��ж�������ȡsession��ֵ�����û��ֵ������null��
		//��ȡsession
		HttpSession session = request.getSession();
		Map<String,Beauty> mapCart = (Map) session.getAttribute("cart");
//3.2��û�ж�����������
		if(mapCart==null){
			out.print("�㻹ʲô��û����");
			response.setHeader("refresh", "2;url="+request.getContextPath()+"/servlet/ShowCart");
			return ;
		}
		out.print("���ﳵ��������Ʒ��<br/>");
//3.3���ж����ʹ�ӡ����
		for (Map.Entry<String, Beauty> b : mapCart.entrySet()) {
			out.print(b.getValue().getName()+"\t"+b.getValue().getNum()+"��<br>");
		}
		
			//Ҳ������List����
/*		List<Book> books = (List<Book>)session.getAttribute("cart");
		if(books==null){
			out.print("�㻹ʲô��û����");
			response.setHeader("refresh", "2;url="+request.getContextPath()+"/servlet/showAllBooksServlet");
			return;
		}
		for (Book book : books) {
			out.write(book.getName()+"<br/>");
		}*/
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
