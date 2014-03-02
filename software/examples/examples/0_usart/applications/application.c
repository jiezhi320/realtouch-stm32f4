/*
 * File      : application.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-01-05     Bernard      the first version
 */
#include <rtthread.h>


void rt_init_thread_entry(void* parameter)
{

	{
		extern int demo_init(void);
		demo_init();
	}	
}



int rt_application_init()
{
    rt_thread_t init_thread;

    init_thread = rt_thread_create("init",
                                   rt_init_thread_entry, RT_NULL,
                                   2048, RT_THREAD_PRIORITY_MAX/3, 20);
    if (init_thread != RT_NULL)
        rt_thread_startup(init_thread);

    return 0;
}
