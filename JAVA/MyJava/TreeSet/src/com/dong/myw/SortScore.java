package com.dong.myw;
import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

import com.dong.io.ReadText;

/*class Score implements Comparable{
	private String str;
	public String getStr() {
		return str;
	}
	public void setStr(String str) {
		this.str = str;
	}
	public Score(String str1,String str2) {
		this.str = str2 + "," + str1;
	}
	@Override
	public int compareTo(Object o) {
		String[] split = str.split(",");
		String[] split2 = ((Score) o).getStr().split(",");
		int num = Integer.parseInt(split2[0]) - Integer.parseInt(split[0]);
		if(num == 0){
			return Integer.parseInt(split[1]) - Integer.parseInt(split2[1]);
		}
		return num;
	}
}*/

class Score2 implements Comparator<String>{

	@Override
	public int compare(String o1, String o2) {
		String[] split = o1.split(",");
		String[] split2 = o2.split(",");
		int num = Integer.parseInt(split2[0]) - Integer.parseInt(split[0]);
		if(num == 0){
			return Integer.parseInt(split[1]) - Integer.parseInt(split2[1]);
		}
		return num;
	}
}

public class SortScore {
	private static final String Score = null;

	public String getMaxScore(TreeSet set){
		String first = (String) set.first();
		set.remove(first);
		return first;
	}
	
	public void add(TreeSet set,String id,String score){
		String str = score +","+id;
		set.add(str);
	}
	public void show(TreeSet set){
		for(Iterator it = set.iterator();it.hasNext();){
			System.out.println(it.next());
		}
	}
	
	public static void main1(String[] args) {
		SortScore ts = new SortScore();
		TreeSet set = new TreeSet(new Score2());
		
		
		ts.add(set, "1","999");
		ts.add(set, "2","1000");
		ts.add(set, "3","888");
		ts.add(set, "4","999");
		
		System.out.println(ts.getMaxScore(set));
		System.out.println(ts.getMaxScore(set));
		System.out.println(ts.getMaxScore(set));
		System.out.println(ts.getMaxScore(set));
	}
}