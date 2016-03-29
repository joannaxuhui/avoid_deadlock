/**
 * Overworked Interns Lab
 * CS 241 - Spring 2016
 */
#include "company.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *work_interns(void *p) {

  Company *company = (Company *)p;
  pthread_mutex_t *left_intern, *right_intern;
  while (running) {
    left_intern = Company_get_left_intern(company);
    right_intern = Company_get_right_intern(company);
    if(left_intern < right_intern){
   	pthread_mutex_lock(left_intern);
    	pthread_mutex_lock(right_intern);
	}
    else if(left_intern > right_intern){
     	pthread_mutex_lock(right_intern);
	pthread_mutex_lock(left_intern);
	}
    else 
    return  NULL;
    	Company_hire_interns(company);
	if(left_intern < right_intern){
    		pthread_mutex_unlock(right_intern);
	 	pthread_mutex_unlock(left_intern);
	}else{
		pthread_mutex_unlock(left_intern);
		pthread_mutex_unlock(right_intern);
	}
    	usleep(rand()%delta);
  }
  return NULL;


}
