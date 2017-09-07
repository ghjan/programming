package com.dong.cart;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.dong.DbUtil.Utils;
import com.dong.entity.Beauty;

public class AddCart extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter out = response.getWriter();
//2.1��ĵ�Cart��������Id��Ȼ��õ�MM
		String id = request.getParameter("id");
		Beauty beauty = Utils.findBeauty(id);
		//�õ�session����
		HttpSession session = request.getSession();
//2.2��鿴���ﳵ�Ƿ��ж�����û�ж����ʹ���һ�����ﳵ
		//��session��ȡ��lMap�����ﳵ��
		Map mapCart = (Map) session.getAttribute("cart");//�ȳ���ȡ�����ݣ����û�оʹ���һ��Map����
		if(mapCart==null){
			mapCart = new HashMap<String,Beauty>();
		}
//2.3�￴�Ƿ����ظ�����Ʒ
		//get(Object key) ����ָ������ӳ���ֵ�������ӳ�䲻�����ü���ӳ���ϵ���򷵻� null��
		Beauty b = (Beauty) mapCart.get(id); 
		if(b==null){
			mapCart.put(id, beauty);
		}else{
			b.setNum(b.getNum()+1);
		}
//2.4��һ��Ҫ����session���ԣ����м�¼���Ǵ�����õ�	
		session.setAttribute("cart", mapCart);//��list�Żص�session����
		out.print("�ɹ����빺�ﳵ��");
		//����session��Чʱ��
		session.setMaxInactiveInterval(60*5);//5min����ʧ
		//ɾ��session,�����˳���¼��ʱ��
		//session.invalidate();
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
