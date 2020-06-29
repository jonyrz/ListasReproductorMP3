#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "listadoble.h"

#define TAM_ARC 50
#define TAM_MUS 100


//Funciones para menus
void menu_principal();
void sub_menu_1(lista *l_principal);
void sub_menu_2(lista *l_principal);
void sub_menu_21(lista *l_principal, char nombre[ ]);

//Funciones para uso de archivos
void archivo_lista(lista *l, char nombre[ ]);
void guardarenarchivo (lista *l, char nombre[ ]);
void reproduccion(lista *l, char nombre[ ]);
void guardar_reproduccion(lista *l, char nombre[ ]);
void ordenar(char* nombre);


int main(int argc, char *argv[]) 
{
	menu_principal();
	return 0;
}

void menu_principal()
{
	int opc,r=0;
	//Inicializo una Lista donde se cargaran todas las canciones de la Biblioteca Principal
		lista l_principal; 
			Initialize(&l_principal);
	
	char biblioteca []= "rolas.txt";
	
				//Cargamos todas las canciones del Blioteca Principal en la lista creada anteriormente
					archivo_lista(&l_principal, biblioteca);	
	
	do{
	system("cls");
	printf("\n\n\t\t * * * * * * PRACTICA 6: iTunas * * * * * * ");
	printf("\n\n\n\t\t :::::::::: MENU ::: PRINCIPAL ::::::::::\n\n");
	printf("\n\t\t  1 :> Biblioteca Musica\n\n\t\t  2 :> Lista de Reproduccion\n\n\t\t  3 :> Salir\n\t\t");
	printf("\n\n\t\t OPCION: ");
		opc=getch();
	
		switch(opc)
		{
			case 49:
				sub_menu_1(&l_principal);
			break;
				
			case 50:
				sub_menu_2(&l_principal);
			break;
				
			case 51:
				printf("\n\n\n\t\t * * * * * * FIN DEL PROGRAMA * * * * * *\n\n");
				exit(0); 
			break;
				
			default:
				printf("\n\n\n\t\t ::::: SELECCIONE UNA OPCION DENTRO DE LOS PARAMETROS :::::\n\n");
				r=1;
				system("PAUSE");
			break;
				
		}	
	}while(r==1);
	
}

void sub_menu_1(lista *l_principal) //Biblioteca Musical 
{  
	int opc,r=0;
	int op; //Variable para el do_while de la opcion 3
	int i,j;
	int w; //Variable para escoger que cancion de la lista se modificara
	char biblioteca []= "rolas.txt";
	char busqueda [TAM_MUS];
			
	 	elemento e1, e2, e3; //Usamos para pasar datos a la lista
		posicion p1;
						
	do{
		system("cls");
			printf("\n\n\t\t * * * * * * PRACTICA 6: iTunas * * * * * * ");
			printf("\n\n\n\t\t :::::::::: SUB :: MENU :: 1 ::::::::::\n\n");
			printf("\n\t\t1.- Mostar Biblioteca\n\n\t\t2.- Agregar una Cancion\n\n\t\t3.- Modificar una Cancion\n\n\t\t4.- Borrar una Cancion\n\n\t\t5.- Buscar Cancion\n\n\t\t6.- Guardar Cambios\n\n\t\t7.- Regresar\n\t\t");
			printf("\n\n\t\t OPCION: ");
				opc=getch();
	
	system("cls");
		switch(opc)
		{
			case 49:		//Listo  Opcion UNO									
				puts("\n\n\t :::::::: LISTA PRINCIPAL DE CANCIONES ::::::::\n\n");
					p1=First(l_principal);			
						
						for (i=1;i<=Size(l_principal);i++)
						{
							e1=Position(l_principal,p1);
							printf("\t%d ::> %s_%s_%s\n",i,e1.artista,e1.cancion,e1.album);
							p1=Following(l_principal,p1);
						}	
						
				system("PAUSE");
				r=1;
				break; 
				
			case 50: 	//Listo  Opcion DOS
				do
				{
					op=0;
					system("cls");
					fflush(stdin);
					printf("\n\n\t NUEVO Artista--> "); gets(e2.artista);
					printf("\n\t NUEVA Cancion--> "); gets(e2.cancion);
					printf("\n\t NUEVA Album  --> "); gets(e2.album);
					strcat(e2.album, "\n");				
						
						Add(l_principal,e2);
							
						puts("\n\n\t ::::: LISTA DE CANCIONES MODIFICADAS :::::\n");
							p1=First(l_principal);			
								for (i=1;i<=Size(l_principal);i++)
								{
									e1=Position(l_principal,p1);
										printf("\n\t%d ::> %s_%s_%s\n",i,e1.artista,e1.cancion,e1.album);
									p1=Following(l_principal,p1);
								}									
							
						puts("\n\n\t * * * * * DESEA HACER ALGO MAS? * * * * *"); printf("\n\n\t(0-Si / 1-No) --> "); scanf("%d",&op);							
				}while(op!=1); r=1;
			break;
				
			case 51:  //Listo
				do
				{
					op=0;
					system("cls");
					puts("\n\n\t :::::::: LISTA PRINCIPAL DE CANCIONES ::::::::\n\n");
						p1=First(l_principal);			
						
							for (i=1;i<=Size(l_principal);i++)
							{
								e1=Position(l_principal,p1);
									printf("\t%d ::> %s_%s_%s\n",i,e1.artista,e1.cancion,e1.album);
								p1=Following(l_principal,p1);
							}				

							puts("");
							puts("\n\t ::::: MODIFICAR LISTA :::::");
							printf("\n\t POSICION DE LA CANCION --> "); scanf("%d",&w);
														
								p1=First(l_principal);		//Buscaremos el dato 
									for (i=1;i<w;i++)
									{
										p1=Following(l_principal,p1);				
									} //Ya tenemos la posicion de la cancion
									e1=Position(l_principal, p1);
									printf("\t %s_%s_%s\n",e1.artista,e1.cancion,e1.album);
		
								fflush(stdin);
								printf("\n\n\t :::::::: INGRESE ::::::::\n");
								printf("\n\t NUEVO Artista--> "); 
								gets(e2.artista);
								printf("\n\t NUEVA Cancion--> "); 
								gets(e2.cancion);
								printf("\n\t NUEVO Album  --> "); 
								gets(e2.album);
								strcat(e2.album, "\n");
								Replace(l_principal, p1, e2);
						
								puts("\n\n\t ::::: LISTA DE CANCIONES MODIFICADAS :::::\n");
								p1=First(l_principal);			
								for (i=1;i<=Size(l_principal);i++)
								{
									e1=Position(l_principal,p1);
										printf("\n\t%d ::> %s_%s_%s\n",i,e1.artista,e1.cancion,e1.album);
									p1=Following(l_principal,p1);
								}				
								puts("\n\n\t * * * * * DESEA HACER ALGO MAS? * * * * *"); printf("\n\n\t(0-Si / 1-No) --> "); scanf("%d",&op);
				}while(op!=1);	r=1;						
				break;
			
			case 52:  //Listo
			do
			{
				op=0;
				system("cls");
				puts("\n\n\t :::::::: LISTA PRINCIPAL DE CANCIONES ::::::::\n\n");
					
					p1=First(l_principal);									
						for (i=1;i<=Size(l_principal);i++)
						{
							e1=Position(l_principal,p1);
							printf("\n\t%d ::> %s_%s_%s\n",i,e1.artista,e1.cancion,e1.album);
								p1=Following(l_principal,p1);
						}				

						puts("");
							puts("\n\t ::::: ELIMINAR DE LA LISTA :::::\n");
							printf("\n\t POSICION DE LA CANCION --> "); scanf("%d",&w);
								
								//Validar caso w>i=Size(&l);
						if( Size(l_principal) != 1)
						{
								p1=First(l_principal);		//Buscaremos el dato 
									for (i=1;i<w;i++)
									{
										p1=Following(l_principal,p1);				
									} 							
							
							Remove(l_principal, p1);
							
						puts("\n\n\t ::::: LISTA DE CANCIONES MODIFICADAS :::::\n");
							p1=First(l_principal);			
								for (i=1;i<=Size(l_principal);i++)
								{
									e1=Position(l_principal,p1);
										printf("\t%d ::> %s_%s_%s\n",i,e1.artista,e1.cancion,e1.album);
									p1=Following(l_principal,p1);
								}				
					puts("\n\n\t * * * * * DESEA HACER ALGO MAS? * * * * *"); printf("\n\n\t(0-Si / 1-No) --> "); scanf("%d",&op);
				
						}
						
						else  //SOLO QUEDA UN ELEMENTO
						{
							Destroy(l_principal);
								printf("\n\n\t* * * * * La Lista esta VACIA * * * * * \n\n");  op=1;
									getch();
						}

			}while(op!=1);	r=1;
				break;
			
			case 53: 
			do{
				op=0;
			system("cls");

				puts("\n\n\t Seleccione la CANCION que desea BUSCAR "); fflush(stdin);				
					printf("\t---> "); gets(busqueda);
										
				     p1 = First(l_principal); j=0;
						for (i=1;i<=Size(l_principal);i++)
						{
							e1=Position(l_principal,p1);
									strtok(e1.album,"\n");
									
								if( strcmp(e1.artista,busqueda)==0 || strcmp(e1.cancion,busqueda)==0 || strcmp(e1.album,busqueda)==0){
									printf("\n\t%s_%s_%s",e1.artista,e1.cancion,e1.album);
									j++;									
								}									

							p1=Following(l_principal,p1);
						}	
						
							if(j==0)
								printf("\n\t* * * * *NINGUNA COINCIDENCIA * * * * *\n");
								
					puts("\n\n\t * * * * * DESEA REALIZAR OTRA BUSQUEDA? * * * * *"); printf("\n\n\t(0-Si / 1-No) --> "); scanf("%d",&op);
					
			}while(op!=1);	
			 r=1;
				break;				
				
			case 54:
					guardarenarchivo(l_principal,biblioteca);
						Destroy(l_principal);
					archivo_lista(l_principal, biblioteca);	
					puts("\n\n\t Guardado...");
				system("PAUSE"); r=1;
				break;
				
			case 55:
				menu_principal(); 				
				break;
				
			default:
				printf("\n\n\n\t\t ::::: SELECCIONE UNA OPCION DENTRO DE LOS PARAMETROS :::::\n\n");
				system("PAUSE"); r=1;
				break;	
		}
			
	}while(r==1);
	
}

void sub_menu_2(lista *l_principal)
{
	int i,w,opc,r=0,op;
	int ay_agregar;
	char listas[]= "Listas.txt";
	char me_lleva[100];
	
	elemento e1, e2, e3; //Usamos para pasar datos a la lista
	posicion p1,p2;
	
	lista l_reproduccion;
	lista l_nueva;
	
			Initialize(&l_reproduccion);
					reproduccion(&l_reproduccion, listas);
			
	do{
	system("cls");
	printf("\n\n\t\t * * * * * * PRACTICA 6: iTunas * * * * * * ");
	printf("\n\n\n\t\t :::::::::: SUB :: MENU :: 2 ::::::::::\n\n");
	printf("\n\n\t\t1.- Mostrar Listas\n\n\t\t2.- Cargar Lista\n\n\t\t3.- Borrar Lista\n\n\t\t4.- Crear Lista\n\n\t\t5.- Regresar\n\t\t");
	printf("\n\n\t\t OPCION: ");
   	  scanf("%d",&opc);
		
		switch(opc){
			case 1:     //Mostrar listas				
				system("cls");				
					puts("\n\n\t ::::: LISTAS GUARDADAS :::::\n");
				if( Size(&l_reproduccion) != 0)
				{
					p1=First(&l_reproduccion);
						for (i=1;i<=Size(&l_reproduccion);i++)
						{
							e1=Position(&l_reproduccion,p1);
							printf("\n\t %d ::> %s",i,e1.album);
								p1=Following(&l_reproduccion,p1);
						}		
					
					puts("\n");
				system("PAUSE"); r=1;										
				}
				
				else
				{
					printf("\t\n\n * * * * * NO HAY LISTAS * * * * *");
					puts("\n");
					system("PAUSE"); r=1;															
				}

				break;
				
			case 2:  					
				system("cls");				
					puts("\n\n\t ::::: LISTAS GUARDADAS :::::\n");
					puts("\n\t Seleccione la lista \n");			
				if( Size(&l_reproduccion) != 0)
				{
					p1=First(&l_reproduccion);
						for (i=1;i<=Size(&l_reproduccion);i++)
						{
							e1=Position(&l_reproduccion,p1);
							printf("\n\t %d ::> %s",i,e1.album);
								p1=Following(&l_reproduccion,p1);
						}		
					
						puts("\n\n\t  Ingrese el Numero de la Lista ");
					printf("\t    ---> "); scanf("%d",&w);
					
								p2=First(&l_reproduccion);		//Buscaremos el dato 
									for (i=1;i<w;i++)
									{
										p2=Following(&l_reproduccion,p2);				
									} //Ya tenemos la posicion de la cancion
										e3=Position(&l_reproduccion, p2);										
										
							sub_menu_21(l_principal, e3.album);
					r=1;
				}
				
				else
				{
					printf("\t\n\n * * * * * NO HAY LISTAS * * * * *");
					puts("\n");
					system("PAUSE"); r=1;															
				}					
						
				break;
				
			case 3:   //Borrar lista
			do{
				op=0;
			system("cls");
				puts("\n\n\t ::::: LISTAS DE REPRODUCCION ::::: \n");
				
				if( Size(&l_reproduccion) != 0)  //Esto sirve mientras la lista tenga elementos
				{									
					p1=First(&l_reproduccion);									
						for (i=1;i<=Size(&l_reproduccion);i++)
						{
							e1=Position(&l_reproduccion,p1);
							printf("\n\t %d ::> %s",i,e1.album);
								p1=Following(&l_reproduccion,p1);
						}				
						puts("\n");
							puts("\n\n\t ::::: ELIMINAR LISTA :::::");
							printf("\n\t POSICION --> "); scanf("%d",&w);
								
						if(Size(&l_reproduccion) != 1)
						{											
								p1=First(&l_reproduccion);		//Buscaremos el dato 
									for (i=1;i<w;i++)
									{
										p1=Following(&l_reproduccion,p1);				
									} 							
							
							Remove(&l_reproduccion, p1);
							
					system("cls");							
						puts("\n\n\t ::::: LISTAS DE REPRODUCCION ::::: \n");
							p1=First(&l_reproduccion);			
								for (i=1;i<=Size(&l_reproduccion);i++)
								{
									e1=Position(&l_reproduccion,p1);
										printf("\n\t %d ::> %s",i,e1.album);
										p1=Following(&l_reproduccion,p1);
								}								
						puts("\n");

				puts("\n\n\t * * * * * DESEA HACER ALGO MAS? * * * * *"); printf("\n\n\t(0-Si / 1-No) --> "); scanf("%d",&op);
				
						}


						else  //SOLO QUEDA UN ELEMENTO
						{
					system("cls");							
						puts("\n\n\t ::::: LISTAS DE REPRODUCCION ::::: \n");
								printf("\n\n\t * * * * * * La LISTA está VACIA * * * * * * \n\n");  op=1;
									Destroy(&l_reproduccion);
									getch();
						}
					
					guardar_reproduccion(&l_reproduccion, listas);
					Destroy(&l_reproduccion);
					reproduccion(&l_reproduccion, listas);						
			}
			
				else
				{
					printf("\n\n\t * * * * * NO HAY LISTAS * * * * *");
						puts("\n");
							system("PAUSE"); r=1; op=1;
				}
												
			}while(op!=1);	r=1;
				break;
				
			case 4:
					Initialize(&l_nueva);				
			do{
				op=0;
			system("cls");
				puts("\n\n\t::::: Crear NUEVA Lista de Reproduccion ::::: ");				
					puts("\n\n\n\tIngrese el NOMBRE de la lista");  fflush(stdin);
					printf("\n\t---> "); gets(e1.album); strcpy(me_lleva,e1.album);
						strcat(e1.album,"\n");  //Esta funcion es necesaria sin ella no se pueden guardar de manera correcta las cadenas en el archivo
						Add(&l_reproduccion,e1);    //Agrega la nueva cancion
							 		
									 guardar_reproduccion(&l_reproduccion, listas);  //Con estas tres funciones me encargo de guardar la lista nueva									 
										Destroy(&l_reproduccion);					// y cargo la lista actualizada...
									reproduccion(&l_reproduccion, listas);
						
						do{
							system("cls");
							 ay_agregar=1;
								printf("\n\n\t NOMBRE DE LA LISTA: %s \n",e1.album);
							
								p1=First(l_principal);
									for (i=1;i<=Size(l_principal);i++)
									{
										e2=Position(l_principal,p1);
										printf("\n\t%d ::> %s_%s_%s",i,e2.artista,e2.cancion,e2.album);
												p1=Following(l_principal,p1);
									}
							
					puts("\n\n\n\n\t :::::::: Introduzca el NUMERO de la cancion ::::::::\n");
					printf("\n\t    ---> "); scanf("%d",&w);

								p1=First(l_principal);		//Buscaremos el dato 
									for (i=1;i<w;i++)
									{
										p1=Following(l_principal,p1);				
									} //Ya tenemos la posicion de la cancion
										e3=Position(l_principal, p1);
								
									Add(&l_nueva,e3);
							
							puts("\n\n\t * * * * * DESEA AGREGAR OTRA CANCION? * * * * *  "); printf("\n\n\t(0-Si / 1-No) --> "); scanf("%d",&ay_agregar);
						}while(ay_agregar!=1);
								
								strcat(me_lleva,".txt");
							guardarenarchivo(&l_nueva, me_lleva);
								Destroy(&l_nueva);//Libero la memoria de la l_nueva

				puts("\n\n\t * * * * * DESEA CREAR UNA LISTA NUEVA? * * * * * "); printf("\n\n\t(0-Si / 1-No) --> "); scanf("%d",&op);				
			}while(op!=1);	r=1;					
				
				break;
				
			case 5:				
					menu_principal();
				break;
				
			default:
				printf("\n\n\n\t\t ::::: SELECCIONE UNA OPCION DENTRO DE LOS PARAMETROS :::::\n\n");
				r=1;
				system("PAUSE");
				break;	
		}
	}while(r==1);
}

void sub_menu_21(lista *l_principal, char nombre[ ])
{
	int opc,r=0;
	int op,j,i,w,ay_agregar;
	char help [100], busqueda[100];
	lista l_aux;
				
				
	elemento e1, e2, e3;
	posicion p1;
				
				j=strlen(nombre);
				
					nombre[j-1] = '\0';  //Resta un salto de linea que trae de mas la cadena
				strcpy(help,nombre); strcat(help,".txt");
				Initialize(&l_aux);	
					archivo_lista(&l_aux, help);
				
	
	do{
	system("cls");
	printf("\n\n\t\t * * * * * * PRACTICA 6: iTunas * * * * * * ");
	printf("\n\n\n\t\t :::::::::: SUB :: MENU :: 2.1 ::::::::::\n\n");
	printf("\n\n\t\t1.- Mostar Lista de Reproduccion\n\n\t\t2.- Agregar una Cancion\n\n\t\t3.- Buscar una Cancion\n\n\t\t4.- Borrar una Cancion\n\n\t\t5.- Regresar\n\t\t");
	printf("\n\n\t\t OPCION: ");
	scanf("%d",&opc);
	
		switch(opc)
		{
			case 1: 					//Listo  Opcion UNO									
			system("cls");			
				puts("\n\n\t :::::::: LISTA PRINCIPAL DE CANCIONES ::::::::\n\n");
					
					p1=First(&l_aux);									
						for (i=1;i<=Size(&l_aux);i++)
						{
							e1=Position(&l_aux,p1);
							printf("\n\t%d ::> %s_%s_%s\n",i,e1.artista,e1.cancion,e1.album);
								p1=Following(&l_aux,p1);
						}	
						
				system("PAUSE"); r=1;								
				break;
				
			case 2:
						do{
							system("cls");
							 ay_agregar=1;
								printf("\n\n\t * * * * * LISTA DE CANCIONES: %s \n",e1.album);
							
								p1=First(l_principal);
									for (i=1;i<=Size(l_principal);i++)
									{
										e2=Position(l_principal,p1);
										printf("\n\t%d ::> %s_%s_%s",i,e2.artista,e2.cancion,e2.album);
												p1=Following(l_principal,p1);
									}
							
					puts("\n\n\n\t ::::: NUMERO DE LA CANCION ::::: \n");
					printf("\n\t    ---> "); scanf("%d",&w);

								p1=First(l_principal);		//Buscaremos el dato 
									for (i=1;i<w;i++)
									{
										p1=Following(l_principal,p1);				
									} //Ya tenemos la posicion de la cancion
										e3=Position(l_principal, p1);
								
									Add(&l_aux,e3);
							
							puts("\n\n\t * * * * * DESEA AGREGAR OTRA CANCION? * * * * * "); printf("\n\n\t(0-Si / 1-No) --> "); scanf("%d",&ay_agregar);
						}while(ay_agregar!=1);				
										
							guardarenarchivo(&l_aux, help);
								Destroy(&l_aux);//Libero la memoria de la l_nueva
							archivo_lista(&l_aux, help);
							
				system("PAUSE"); r=1;				
				
				break;

			case 3:
			do{
				op=0;
			system("cls");

				puts("\n\n\t\n ::::: INTRODUZCA LA CANCION QUE DESEA BUSCAR :::::"); fflush(stdin);				
					printf("\n\n\n\t---> "); gets(busqueda);
										
				     p1 = First(&l_aux); j=0;
						for (i=1;i<=Size(&l_aux);i++)
						{
							e1=Position(&l_aux,p1);
									strtok(e1.album,"\n");
									
								if( strcmp(e1.artista,busqueda)==0 || strcmp(e1.cancion,busqueda)==0 || strcmp(e1.album,busqueda)==0){
									printf("\n\t%s_%s_%s",e1.artista,e1.cancion,e1.album);
									j++;									
								}									

							p1=Following(&l_aux,p1);
						}	
						
							if(j==0)
								printf("\n\n\t * * * * * NINGUNA COINCIDENCIA * * * * *\n");
								
					puts("\n\n\t * * * * * DESEA REALIZAR OTRA BUSQUEDA? * * * * *"); printf("\n\n\t(0-Si / 1-No) --> "); scanf("%d",&op);
					
			}while(op!=1);	
			 r=1;
				
				break;
				
			case 4:
			do{
				op=0;
			system("cls");
				puts("\n\n\t :::::::: LISTA PRINCIPAL DE CANCIONES ::::::::\n\n");
					
					p1=First(&l_aux);									
						for (i=1;i<=Size(&l_aux);i++)
						{
							e1=Position(&l_aux,p1);
							printf("\n\t%d ::> %s_%s_%s\n",i,e1.artista,e1.cancion,e1.album);
								p1=Following(&l_aux,p1);
						}				

						puts("");
							puts("\n\n\t ::::: LISTA DE CANCIONES MODIFICADAS :::::\n");
							printf("\n\n\tPOSICION DE LA CANCION--> "); scanf("%d",&w);
								
								p1=First(&l_aux);		//Buscaremos el dato 
									for (i=1;i<w;i++)
									{
										p1=Following(&l_aux,p1);				
									} 							
							
							Remove(&l_aux, p1);
							
						puts("\n\n\t ::::: CANCIONES MODIFICADAS ::::: \n");
							p1=First(&l_aux);			
								for (i=1;i<=Size(&l_aux);i++)
								{
									e1=Position(&l_aux,p1);
										printf("\n\t%d ::> %s_%s_%s\n",i,e1.artista,e1.cancion,e1.album);
									p1=Following(&l_aux,p1);
								}				
				puts("\n\n\t * * * * * DESEA HACER ALGO MAS? * * * * *"); printf("\n\n\t(0-Si / 1-No) --> "); scanf("%d",&op);


			}while(op!=1);	r=1;				

							guardarenarchivo(&l_aux, help);
								Destroy(&l_aux);//Libero la memoria de la l_nueva
							archivo_lista(&l_aux, help);
				
				break;

			case 5:
				sub_menu_2(l_principal); 
				break;
				
			default:
				printf("\n\n\n\t\t ::::: SELECCIONE UNA OPCION DENTRO DE LOS PARAMETROS :::::\n\n");
				r=1;
				system("PAUSE");
				break;	
		}
	}while(r==1);
}



//Funciones para uso de archivos
void archivo_lista(lista *l, char nombre[ ]) 
{
	elemento e1;
	char c;
	int i=0,j;
	char *ayuda;
	char aux[TAM_MUS];

//			puts(nombre);
	
		    FILE *pf;
	          pf=fopen(nombre,"rt"); 
	
        if(pf==NULL) //Valida caso en que no se encuentre archivos
         {
           puts ("\n\n\t * * * * * Problema al abrir archivos * * * * *\n");
           	exit (-1);
         }	
               

		//Empezar a llenar la lista...			   	
	while(fgets(aux,TAM_MUS,pf)) //Itera hasta que devuelve el NULL
	{	//puts(aux);					
		ayuda=strtok (aux,"_");
			while (ayuda != NULL)
  				{
    				strcpy(e1.artista,ayuda);
    				ayuda = strtok (NULL, "_");
    				//puts(e1.cancion);
    				
    				strcpy(e1.cancion,ayuda);
    				ayuda = strtok (NULL, "_");
    				//puts(e1.artista);
    				
    				strcpy(e1.album,ayuda);
    				ayuda = strtok (NULL, "_");
    				//puts(e1.album);
    				
    				Add(l,e1);  //Considera &l
  				}
	}

	//rewind(pf); //Reinicia el archivo para su uso

    fclose(pf);
}

void guardarenarchivo (lista *l, char nombre[ ]) 
{
			
     FILE* archivo = fopen(nombre, "wt");
     char aux[300];
     
     int i;
     posicion p1;
     elemento e1;
  
          if(archivo==NULL) //Valida caso en que no se encuentre archivos
         {
           puts ("\n\n\t * * * * * Problema al crear archivos * * * * * \n");
           	exit (-1);
         }	

     
     p1 = First(l);
		for (i=1;i<=Size(l);i++)
		{
				e1=Position(l,p1);
				fprintf(archivo,"%s_%s_%s",e1.artista,e1.cancion,e1.album);
			p1=Following(l,p1);
		}	
				
	fclose(archivo)	;
		
		//ordenar(nombre);
		
	//	puts(nombre);
}

void reproduccion(lista *l, char nombre[ ]) //Saca las listas de reproduccion
{	
	elemento e1;		
	char aux[TAM_MUS];

//			puts(nombre);
	
		    FILE *pf;
	          pf=fopen(nombre,"rt"); 
	
        if(pf==NULL) //Valida caso en que no se encuentre archivos
         {
           puts ("\n\n\t * * * * * Problema al abrir archivos * * * * *\n");
           	exit (-1);
         }	
               

		//Empezar a llenar la lista...			   	
	while(fgets(aux,TAM_MUS,pf)) //Itera hasta que devuelve el NULL
	{	
	//	puts(aux);
			strcpy(e1.album,aux);
			 Add(l,e1);	
	}
		
	//rewind(pf); //Reinicia el archivo para su uso
	
	    fclose(pf);

}

void guardar_reproduccion(lista *l, char nombre[ ])
{
	     FILE* archivo = fopen(nombre, "wt");
     char aux[300];
     
     int i;
     posicion p1;
     elemento e1;
  
          if(archivo==NULL) //Valida caso en que no se encuentre archivos
         {
           puts ("\n\n\t * * * * * Problema al crear archivos * * * * *\n");
           	exit (-1);
         }	

     
     p1 = First(l);
		for (i=1;i<=Size(l);i++)
		{
				e1=Position(l,p1);
				fputs(e1.album,archivo);
			p1=Following(l,p1);
		}	
				
	fclose(archivo)	;
		
}

