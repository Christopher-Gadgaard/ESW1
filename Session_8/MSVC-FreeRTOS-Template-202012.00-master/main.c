#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

/* Priorities at which the tasks are created. */
#define TASK_MY_TASK_PRIORITY			( tskIDLE_PRIORITY + 1 )
#define	TASK_MY_SECOND_TASK_PRIORITY	( tskIDLE_PRIORITY + 2 )
#define TASK_MY_THRID_TASK_PRIORITY     (tskIDLE_PRIORITY + 3)
#define TASK_MY_FOURTH_TASK_PRIORITY     (tskIDLE_PRIORITY + 4)
/* Task stack sizes*/
#define TASK_MY_TASK_STACK				( configMINIMAL_STACK_SIZE )
#define	TASK_MY_SECOND_TASK_STACK		( configMINIMAL_STACK_SIZE )
#define	TASK_MY_THRID_TASK_STACK		( configMINIMAL_STACK_SIZE )
#define	TASK_MY_FOURTH_TASK_STACK		( configMINIMAL_STACK_SIZE )

/* Task Handles */
TaskHandle_t _taskSecondHandle = NULL;
TaskHandle_t _taskThridHandle = NULL;
TaskHandle_t _taskFourthHandle = NULL;



// --------------------------------------------------------------------------------------
void taskMyTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		vTaskDelay(pdMS_TO_TICKS(200));
		puts("Hi from My Task");
	}
}

// --------------------------------------------------------------------------------------
void taskMySeccondTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;
	
	for (;;)
	{
		vTaskDelay(pdMS_TO_TICKS(100));
		puts("Hi from My Second Task");
	}
}

//---------------------------------------------------------------------------------------
void taskMyThridTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	for (;;)
	{
		vTaskDelayUntil(&xLastWakeTime,pdMS_TO_TICKS(100));
		puts("Hi from My Thrid Task");
	}
}

void taskMyFourthTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	for (;;)
	{
		vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(100));
		puts("Hi from My Thrid Task");
	}
}

// --------------------------------------------------------------------------------------
void main(void)
{
	/* Create the task, not storing the handle. */
	xTaskCreate(
		taskMyTask,       /* Function that implements the task. */
		"MyTask",          /* Text name for the task. */
		TASK_MY_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)1,    /* Parameter passed into the task. */
		TASK_MY_TASK_PRIORITY,/* Priority at which the task is created. */
		NULL);      /* Used to pass out the created task's handle. */

		/* Create the task, storing the handle. */
	xTaskCreate(
		taskMySeccondTask,       /* Function that implements the task. */
		"MySecondTask",          /* Text name for the task. */
		TASK_MY_SECOND_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)2,    /* Parameter passed into the task. */
		TASK_MY_SECOND_TASK_PRIORITY,/* Priority at which the task is created. */
		&_taskSecondHandle);      /* Used to pass out the created task's handle. */

	/* Create the task, not storing the handle. */
	xTaskCreate(
		taskMyThridTask,       /* Function that implements the task. */
		"MyThridTask",          /* Text name for the task. */
		TASK_MY_THRID_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)3,    /* Parameter passed into the task. */
		TASK_MY_THRID_TASK_PRIORITY,/* Priority at which the task is created. */
		&_taskThridHandle);      /* Used to pass out the created task's handle. */

	/* Create the task, storing the handle. */
	xTaskCreate(
		taskMyFourthTask,       /* Function that implements the task. */
		"MyFourthTask",          /* Text name for the task. */
		TASK_MY_FOURTH_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)4,    /* Parameter passed into the task. */
		TASK_MY_FOURTH_TASK_PRIORITY,/* Priority at which the task is created. */
		&_taskFourthHandle);      /* Used to pass out the created task's handle. */

	// Let the operating system take over :)
	vTaskStartScheduler();
}