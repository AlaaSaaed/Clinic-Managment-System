#ifndef C_PROJECT_H
#define C_PROJECT_H
#include "STD_Types.h"



typedef struct patient{
	u8 name[15];
	u32 age;
	u32 id;
	u8 gender;
	struct patient *next;
}St_Patient; 

typedef struct reservation{
	f32 time;
	u32 id;
	struct reservation *next;
}St_Reservation; 

void AddPatient(St_Patient **head, u32 id, u8 *name, u32 age, u8 gender){
	if(*head==NULL){
		(*head) = (St_Patient *)malloc(sizeof(St_Patient));
		for(u32 i=0;i<15;i++){
			(*head)->name[i]= name[i];
		}
		(*head)->id=id;
		(*head)->age=age;
		(*head)->gender=gender;
		(*head)->next=NULL;
		
	}
	else{
		St_Patient *last = *head;
		St_Patient *new = (St_Patient *)malloc(sizeof(St_Patient));
		for(u32 i=0;i<15;i++){
			new->name[i]= name[i];
		}
		new->id = id;
		new->age = age;
		new->gender = gender;
		new->next=NULL;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=new;	
	}
}


void PrintPatientRecord(St_Patient **head, u32 id){
	St_Patient *last = *head;
	while(last!=NULL && last->id!=id){
		last=last->next;
	}
	if(last!=NULL){
		printf("ID: %d\nName: %s\nAge: %d\nGender: %c\n",last->id,last->name,last->age,last->gender);
	}
	else{
		printf("This ID is not exist\n");
	}
}


void EditPatientRecord(St_Patient **head, u32 id, u8 *name, u32 age, u8 gender){
	
	St_Patient *last = *head;
	while(last != NULL && last->id!=id){
		last = last->next;
	}
	if(last!=NULL){
		for(u32 i=0;i<15;i++){
			last->name[i]= name[i];
		}
		last->gender = gender;
		last->age = age;
	}
	else{
		printf("This ID is not exist\n");
	}
}


void PrintAvailableReservations(St_Reservation **head){
	St_Reservation *last = *head;
	while(last!=NULL){
		if(last->id==-1){
			printf("%.2f\t",last->time);
		}
		last=last->next;
	}
}

void ReserveSlot(St_Reservation **head, u32 id, f32 slot){
	St_Reservation *last = *head;
	while(last != NULL && last->time!=slot){
		last = last->next;
	}
	if(last!=NULL){
		last->id=id;
	}
}


void PrintReservations(St_Reservation **head){
	St_Reservation *last = *head;
	St_Reservation *ptr = *head;
	while(last!=NULL){
		if(last->id!=-1){
			break;
		}
		last=last->next;
	}
	if(last!=NULL){
		printf("\nToday's reservations:\n\n");
		printf("Patient ID\tTime\n");
		while(ptr!=NULL){
			if(ptr->id!=-1){
				printf("%7d\t\t%.2f\n",ptr->id,ptr->time);
			}
			ptr=ptr->next;
		}
	}
	else{
		printf("\nThere is no reservations\n");
	}
	
}


void CancelReservation(St_Reservation **head, u32 id){
	St_Reservation *last = *head;
	while(last != NULL && last->id!=id){
		last = last->next;
	}
	if(last!=NULL){
		last->id=-1;
	}
	else{
		printf("This id isn't exist");
		
	}
}

u16 CheckID(St_Patient **head, u32 id){
	St_Patient *last = *head;
	while(last != NULL && last->id!=id){
		last = last->next;
	}
	if(last!=NULL){
		return 1;
	}
	else{
		return 0;
	}
}


u16 CheckReservation(St_Reservation **head, u32 id){
	St_Reservation *last = *head;
	while(last != NULL && last->id!=id){
		last = last->next;
	}
	if(last!=NULL){
		return 1;
	}
	else{
		return 0;
	}
}



void CreateSlots(St_Reservation **head){
	*head = (St_Reservation *)malloc(sizeof(St_Reservation));
	St_Reservation *slot2 = (St_Reservation *)malloc(sizeof(St_Reservation));
	St_Reservation *slot3 = (St_Reservation *)malloc(sizeof(St_Reservation));
	St_Reservation *slot4 = (St_Reservation *)malloc(sizeof(St_Reservation));
	St_Reservation *slot5 = (St_Reservation *)malloc(sizeof(St_Reservation));
	(*head)->time=2;
	(*head)->id=-1;
	(*head)->next=slot2;
	slot2->time=2.30;
	slot2->id=-1;
	slot2->next=slot3;
	slot3->time=3;
	slot3->id=-1;
	slot3->next=slot4;
	slot4->time=4;
	slot4->id=-1;
	slot4->next=slot5;
	slot5->time=4.30;
	slot5->id=-1;
	slot5->next=NULL;
}
	

#endif
