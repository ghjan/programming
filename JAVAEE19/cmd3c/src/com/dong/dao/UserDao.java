package com.dong.dao;

import com.dong.domain.User;

public interface UserDao {
	
	/**
	 * ����û�
	 * @param user
	 */
	public void addUser(User user);
	
	public User findUser(User user);
}
