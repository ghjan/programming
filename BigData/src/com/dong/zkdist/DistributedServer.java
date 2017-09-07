package com.dong.zkdist;

import java.io.IOException;

import org.apache.zookeeper.CreateMode;
import org.apache.zookeeper.KeeperException;
import org.apache.zookeeper.WatchedEvent;
import org.apache.zookeeper.Watcher;
import org.apache.zookeeper.ZooDefs.Ids;
import org.apache.zookeeper.ZooKeeper;
import org.junit.Before;

public class DistributedServer {
	private static final String connectString = "mini1:2181";
	private static final int sessionTimeout = 2000;
	private static final String parentNode = "/servers";
	static ZooKeeper zk = null;
	/*
	 * ���ڳ�ʼ��ZooKeeper�������ü�����
	 */
	public void getConnect() throws IOException{
		zk = new ZooKeeper(connectString,sessionTimeout,new Watcher(){
			@Override
			public void process(WatchedEvent event) {
				// ÿ�νڵ㱻���ӣ�ɾ��������ִ������ص�������   ���Ǹ�����ڵ��data�ǲ��ᴥ����
				System.out.println(event.getType() + "---" + event.getPath());
				try {
					zk.getChildren("/", true);
				} catch (Exception e) {
				}
			}
		});
	}
	/*
	 * ��zk��Ⱥע���������Ϣ
	 */
	public void registerServer(String hostname) throws KeeperException, InterruptedException {
		String create = zk.create(parentNode+"/server", hostname.getBytes(), Ids.OPEN_ACL_UNSAFE, CreateMode.EPHEMERAL_SEQUENTIAL);
		System.out.println(hostname+"is online.."+create);
	}
	/**
	 * ҵ����
	 */
	public void handleBussiness(String hostname) throws InterruptedException {
		System.out.println(hostname + "start working.....");
		Thread.sleep(Long.MAX_VALUE);
	}
	public static void main(String[] args) throws IOException, KeeperException, InterruptedException {
		//��ȡ���ӣ���ʼ��zk���������
		DistributedServer server = new DistributedServer();
		server.getConnect();
		
		// ����zk����ע���������Ϣ�����Ǵ���һ���ڵ��
		server.registerServer(args[0]);
		
		// ����ҵ����(�������sleep����)
		server.handleBussiness(args[0]);
	}
}
