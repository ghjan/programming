package com.dong.history;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.dong.DbUtil.Utils;
import com.dong.entity.Beauty;

public class ShowOneBeauty extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter w = response.getWriter();
		
		//��ȡShowAllbeauty��get��ʽ��������id
		String id = request.getParameter("id");
		//ͨ��id��MM
		Beauty beauty = Utils.findBeauty(id);
		w.print(beauty);
		
		//�ѵ�ǰ����������idд�ص��ͻ���
		String history = organizeId(id,request);//����һ���ַ���������洢���������MMid
		Cookie cookie = new Cookie("history", history);
		cookie.setPath("/");
		cookie.setMaxAge(Integer.MAX_VALUE);
		response.addCookie(cookie);
	}
	/**
	 * �ͻ���							showAllBooks				showBookDetail
	 * ��Cookie����û��historyBookId		1						historyBookId=1
	 * historyBookId=1					2						historyBookId=2-1
	 * historyBookId=1-2				2						historyBookId=2-1
	 * historyBookId=1-2-3				2						historyBookId=2-1-3
	 * historyBookId=1-2-3				4						historyBookId=4-1-2
	 */
	private String organizeId(String id, HttpServletRequest request) {
		//�õ��ͻ��˵�Cookie
		Cookie[] cks = request.getCookies();
		//������û��name����history��cookie
		Cookie historyCk = null;
		for (int i = 0;cks!=null && i < cks.length; i++) {
			if("history".equals(cks[i].getName())){
				historyCk = cks[i];
			}
		}
		if(historyCk == null){
			return id;
		}
		
		//ȡ��ԭ�����ַ���
		String value = historyCk.getValue();
		//�ָ�ԭ�����ַ���
		String[] split = value.split("-");
		//ȫ���ŵ�������
//		LinkedList(Collection<? extends E> c) 
//      					  ����һ������ָ�� collection �е�Ԫ�ص��б���ЩԪ�ذ��� collection �ĵ��������ص�˳�����С�
		LinkedList<String> list = new LinkedList<String>(Arrays.asList(split));//static List<T> asList ����һ����ָ������֧�ֵĹ̶���С���б�
		
		if(list.contains(id)){//���������ǰid��ֵ����ɾ�����id
			list.remove(id);
		}else if(list.size()>3){
			list.removeLast();//�����һ��idɾ�� 
		}
		list.addFirst(id);//�������id��ӵ���ǰ��
		
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < list.size(); i++) {
			if(0!=i){
				sb.append("-");
			}
			sb.append(list.get(i));
		}
		
		System.out.println(sb);
		System.out.println("id = "+id);
		
		return sb.toString();
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
