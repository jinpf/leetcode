#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: jinpf
# @Date:   2015-07-06 20:55:54
# @Last Modified by:   jinpf
# @Last Modified time: 2015-07-06 20:59:37

def quick_sort(slist):
	if slist:
		return quick_sort([x for x in slist[1:] if x <= slist[0]]) \
		       + [slist[0]] \
		       + quick_sort([x for x in slist[1:] if x > slist[0]])
	else:
		return []

if __name__ == '__main__':
	a = [2,7,1,2,5,9,3,7,5]
	print quick_sort(a)