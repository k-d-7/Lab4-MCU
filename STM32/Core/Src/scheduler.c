#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Add_Task ( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){
	if(current_index_task < SCH_MAX_TASKS){

		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY;
		SCH_tasks_G[current_index_task].Period =  PERIOD;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;


		current_index_task++;
	}
}

void SCH_Update(void) {
//	uint8_t index;
//	for (index = 0; index < SCH_MAX_TASKS; index++) {
//		if (SCH_tasks_G[index].pTask) {
//			if (SCH_tasks_G[index].Delay == 0) {
//				SCH_tasks_G[index].RunMe += 1;
//				if (SCH_tasks_G[index].Period) {
//					SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
//				}
//			} else {
//				SCH_tasks_G[index].Delay--;
//			}
//		}
//	}
	for(int i = 0; i < current_index_task; i++){
			if (SCH_tasks_G[i].Delay > 0){
				SCH_tasks_G[i].Delay --;
			}else{
				SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
				SCH_tasks_G[i].RunMe += 1;
			}
		}
}

void SCH_Dispatch_Tasks(void){
	for(int i = 0; i < current_index_task; i++){
		if(SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();

			if (SCH_tasks_G[i].Period == 0) {
				SCH_Delete_Task(i);
			}
		}
	}
}

void SCH_Delete_Task(uint32_t taskID) {
	int i = 0;
	while (i < taskID) {
		i++;
	}
	for (; i < current_index_task; i++) {
		SCH_tasks_G[i] = SCH_tasks_G[i + 1];
		SCH_tasks_G[i].TaskID = i;
	}
	current_index_task--;
}
