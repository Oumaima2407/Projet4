#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class client {
	private:
	int id ;
	string nom ;
	string prenom ;
	string ad ;
	 public:
	 client();
	 void Affich_c();
	 void Saisie_c();
	 int Get_id();
	 string Get_nom();
	 string Get_prenom();
	 string Get_add();
	 void Set_id(int idd);
	 void Set_nom(string nomm);
	 void Set_prenom(string prenomm);
	 void Set_ad(string add);	
	  // Surcharge de l'opérateur d'affectation
     void operator=(client &cli);	
};
 class chambre {
 	private:
 	int code ;
 	string ntel ;
 	public:
 	chambre();
 	void Affich_ch();
 	void Saisie_ch();
	int Get_code();
    string Get_N();
	void Set_code(int codee);
	void Set_N(string N);
	bool Compare_C(chambre Ch1 );
	 // Surcharge de l'opérateur d'affectation
    void operator=(chambre &ch);
	    
 };
 class date{
 	private:
 	int j;
 	int m;
 	int a;
 	public:
 	date();
 	void saisi_date();
 	void set_a(int aa);
	void set_m(int mm);
	void set_j(int jj);
 	int get_j();
	int get_m();
	int get_a();
	void affich_date();
	bool date_aujrd();////////////////////
	 // Surcharge de l'opérateur d'affectation
    void operator=(date &da);	
	 
 };
 
 class reservation{
 	private:
 	int id;
 	int nbch;
 	chambre ch[7];
 	client c;
 	date d_debut;
 	date d_fin;
 	int etat;//0 annule 1 valide
 	public:
	void set_chembre(int indice_tableau,string ntell);//////////
 	reservation();
 	int etat_ch(chambre chh);//!-1 existe dans la reservation -1 existe pas
	int ajout_ch_res();
	void saisi_res();
	void affiche_reserv();
	void supp_ch(chambre ch1);
	void etat_reserv();//1reserver 0annuler(modifier l'etat de reservation)
    client get_cli();
	int get_idr();
	int get_etatr();
	date get_dated();
	date get_datef();
	void duree_res();
	int set_idr(int idr);
	// Surcharge de l'opérateur d'affectation
	 void operator=(reservation &ree);
	 
 };
 
 
 //client
     client::client(){
	 }
     void client::Affich_c()
	  {
	    cout<<"Identifient :"<<id<<endl ;
    	cout<<"Nom :"<<nom<<endl ;
    	cout<<"Prenom :"<<prenom<<endl ;
	    cout<<"Adresse :"<<ad<<endl ;
      }
 	 void client::Saisie_c()
	  {
 	 	cout<<"Endrer l'id du client";
	 	cin>>id;
	 	cout<<"Entrer le nom du client";
	 	cin>>nom;
	 	cout<<"Entrer le prenom du client";
	 	cin>>prenom;
	 	cout<<"Entrer l'adresse du client";
	 	cin>>ad;		
	  }
	 int client::Get_id()
	 {
	 	return id ;
	 }
	 string client::Get_nom()
	 {
	 	return nom ;
	 }
	 string client :: Get_prenom()
	 {
	 	return prenom ;
	 }
	 string client::Get_add()
	 {
	 	return ad ;
	 }
	 void client::Set_id(int idd)
	 {
	 	id=idd;
	 }
	 void client::Set_nom(string nomm)
	 {
	 	nom=nomm;
	 }
	 void client::Set_prenom(string prenomm)
	 {
	 	prenom=prenomm;
	 }
	 void client::Set_ad(string add)
	 {
	 	ad=add;
	 }	
	 void client::operator=(client &cli) 
	 { 
	    id=cli.id;
	    nom=cli.nom;
	    prenom=cli.prenom;
	    ad=cli.ad;
     } 
	 
//chambree	  
    chambre::chambre()
	{
 		
	}
	void chambre::Affich_ch()
	{
 		cout<<"Code :"<<code<<endl ;
	 	cout<<"Numero de telephone :"<<ntel<<endl ;	
	}
 	void chambre::Saisie_ch()
	{
 	 	cout<<"Entrer le code ce chambre";
 	 	cin>>code;
 	 	cout<<"Entrer le num de tel de la chambre";
 	 	cin>>ntel;
   	}
	
	int chambre::Get_code()
	{
	  	return code;
    }
 
	string chambre::Get_N()
	{
	  	return ntel ;
	}
	void chambre::Set_code(int codee)
	{
	  	code=codee;
	}
	void chambre::Set_N(string N)
	{
	  	ntel=N ;
	}

	  
	bool chambre::Compare_C(chambre Ch1)
	{
	  	if(Ch1.Get_code()==code)
	  	return true ;
	  	return false ;
	}
	void chambre::operator=(chambre &ch)
    { 
        code=ch.code;
        ntel=ch.ntel;
        
    }
	  
//datee	  
	date::date()
	{ 
	    j=1;
	    m=1;
	    a=1;
	}
	void date::saisi_date()
 	{
 		do{
 		cin>>j;
 		cin>>m;
 		cin>>a;
 		}while(a<0||m<1||m>12||j<1||((m==4||m==6||m==9||m==11)&&j>30)||((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&j>31)||(m==2&&(a%4==0&&a%100!=0||a%400==0)&&j>29)||(m==2&&!(a%4==0&&a%100!=0||a%400==0)&&j>28));
	}
	void date::affich_date()
	{
		cout<<j<<"/"<<m<<"/"<<a<<endl;
	}
	bool date::date_aujrd()
	{
		 time_t actuel = time(0);
		 tm *ltm = localtime(&actuel);
		 if(a==1900 + ltm->tm_year && m==1 + ltm->tm_mon && j==ltm->tm_mday)
		 {
		 	return true;
		 }
		 return false;
	}
 	int date::get_j(){
 		return j;
	}
	int date::get_m(){
 		return m;
	}
	int date::get_a(){
 		return a;
	}
	void date::set_a(int aa)
    {
    	a=aa;
    }
    void date::set_m(int mm)
    {
    	m=mm;
    }
    void date::set_j(int jj)
    {
 	    j=jj;
    }
	void date::operator=(date &da)
    { 
        j=da.j;
        m=da.m;
        a=da.a;
    }
	
	
//reservation
 reservation::reservation()
     {
	    etat=1;
	    nbch=0;
	 }
 void reservation::affiche_reserv()
	 {
	 	cout<<"L'ID de la reservation: "<<id<<endl;
	 	cout<<"Date debut de reservation: ";
	 	d_debut.affich_date();
	 	cout<<"Date fin de reservation: ";
	 	d_fin.affich_date();
	 	if(etat==1)
	 	{
	 		cout<<"Etat de reservation: Valide"<<endl;
		}
		else
		{
			cout<<"Etat de reservation: Annule"<<endl;
		}
		cout<<"Client: "<<endl;
		c.Affich_c();
		cout<<"Les chambres de la reservation: "<<endl;
	 	for(int i=0;i<nbch;i++)
	 	{
	 		ch[i].Affich_ch();
		}
	 	
	 }
	 void reservation::supp_ch(chambre ch1)
	 {
	 	int test;
	 	test=etat_ch(ch1);
	 	if(test==-1)
		{
			cout<<"Chambre n'existe pas dans cette reservaion"<<endl;
		}
		else
		{
			for(int j=test;j<nbch;j++)
	 			{
	 				ch[j]=ch[j+1];
				}
				nbch--;
				cout<<"Chambre supprimer avec succes"<<endl;
		}

	 }
	 void reservation::etat_reserv()
	 {
	 	if(etat==0)
	 	{
	 		etat=1;
	 		cout<<"Reservation valider avec succes"<<endl;
		}
		else
		{
			etat=0;
			cout<<"Reservation annuler avec succes"<<endl;
		}
	 }  
	int reservation::etat_ch(chambre chh)
 	{
 		for(int i=0;i<nbch;i++)
 		{
 			if(chh.Get_code()==ch[i].Get_code())
 			{
 				return i;//chambre exixte dans la reservtion
			}
		}
		return -1;//n'existe pas dans la reservation
	 }
	 void reservation::saisi_res()
	 {
	        int tst,ne;
	 	    cout<<"Entrer l'id de reservation";
	 	    cin>>id;
	 	    cout<<"Entrer les info du client"<<endl;
	 	    c.Saisie_c();//lors de la reservation j'ajoute le client au tableau des client si il n'existe pas
	 	    cout<<"Entrer la date de debut de reservation (jour mois annee)"<<endl;
	 	    d_debut.saisi_date();
	 	    cout<<"Entrer la date de fin de reservation (jour mois annee)"<<endl;
	 	    d_fin.saisi_date();
	 	
	 }
	 int reservation::ajout_ch_res()
	 {
	 	//test si on a pas depasse 7 chambre
	  if(nbch<7)
	   {
	 	chambre d;
	 	int test;
	 	d.Saisie_ch();
	 	test=etat_ch(d);
	 	//test si une chambre existe dans la reservation
	 	if(test!=-1)
	 	{
	 		
	 		cout<<"Cette chambre exite deja dans cette reservation"<<endl;
	 		return 0;
		}
		else
		{
				ch[nbch]=d;
			    nbch++;
			    cout<<"Chambre ajouter avec succes a cette reservation"<<endl;
			    return 1;
		}
	   }
	   else
	   {
	   	cout<<"Vous avez deja 7 chambres dans cette reservation"<<endl;
	   	return 0;
	   }
	 }
	 client reservation::get_cli()
	 {
	 	return c;
	 }
	 int reservation::get_idr()
	 {
	 	return id;
	 }
	 int reservation::get_etatr()
	 {
	    return etat;
	 }
	 date reservation::get_dated()
	 {
		return d_debut;
	 }
	 date reservation::get_datef()
	 {
		return d_fin;
	 }
	 void reservation::set_chembre(int indice_tableau,string ntell)//je ne modifi que le numtel et l'etat si je veux modifier le code je supp la chanmbe et j'ajoute la nouvelle
	 {
		ch[indice_tableau].Set_N(ntell);
	   
	 }
	 int reservation::set_idr(int idr)
	 {
	 	id=idr;
	 }
	// Surcharge de l'opérateur d'affectation
	 void reservation::operator=(reservation &ree) 
	 { 
	    id=ree.id;
 	    nbch=ree.nbch;
 	    c=ree.c;
 	    d_debut=ree.d_debut;
 	    d_fin=ree.d_fin;
 	    etat=ree.etat; 
 	    for(int i=0;i<7;i++)
 	    {
 	    	ch[i]=ree.ch[i];
		}
	    
     } 

	 
	 
	 
//4 fonctions
	 int test_si_client_reserve(client cc,reservation res[200],int n)
	 {
	 	int i;
	 	for(i=0;i<n;i++)
	 	{
	 		if(res[i].get_cli().Get_id()==cc.Get_id())
	 		{
	 			return i;//client a deja effectuer une reservation
			}
		}
		return -1;//client n'a jamais fait une reservation
	 }
	  int test_si_reserve_eff(reservation rr,reservation res[200],int n)
	 {
	 	int i;
	 	for(i=0;i<n;i++)
	 	{
	 		if(res[i].get_idr()==rr.get_idr())
	 		{
 			    return i;//res existe et valide 
			}
		}
		return -1;//res n'existe pas
	 }
	 void ajout_reserv(reservation res[200],int &n)
	 {
	 	reservation rr;
	 	int test;
	 	rr.saisi_res();
	 	test=test_si_reserve_eff(rr,res,n);
	 	if(test==-1)
	 	{
	 	  res[n]=rr;
		  n++;	
		  cout<<"Reserservation ajouter avec succes"<<endl;
		}
		else
		{
			cout<<"Reservation existe deja!!"<<endl;
		}
	 	
	 }
	 void modifier_ch(reservation rr,chambre cc,reservation res[200],int n)
	 {
	 	int test;
	 	test=test_si_reserve_eff(rr,res,n);
	 	if(test==-1)
	 	{
	 		cout<<"Cette reservation n'existe pas"<<endl;
		}
		else
		{
			int x=res[test].etat_ch(cc);
			if(x==-1)
			{
				cout<<"Cette chambre n'existe pas"<<endl;
			}
			else
			{
				string ntell;
				cout<<"Entrer le num de tel";
				cin>>ntell;
				res[test].set_chembre(x,ntell);
				cout<<"Chambre modifier avec succes"<<endl;
			}

		}
	 }
	 void supp_reserv(reservation res[200],int &n,reservation rr)
	 {
	 	int test;
	 	test=test_si_reserve_eff(rr,res,n);
	 	if(test==-1)
	 	{
	 		cout<<"Cette reservation n'existe pas"<<endl;
		}
		else
		{
			for(int i=test;i<n;i++)
			{
				res[i]=res[i+1];
			}
			n--;
			cout<<"Reservation supprimer avec succes"<<endl;
		}
	 }
	 void affich_tout_res(reservation res[200],int n)
	 {
	 	for(int i=0;i<n;i++)
	 	{
	 		res[i].affiche_reserv();
	 		cout<<endl;
		}
	 }
	 
	 reservation * res_eff_aujrd(reservation res[200],int n,int &nn)
	 {
	 	reservation *rr=new reservation[50];
	 	nn=0;
	 	for(int i=0;i<n;i++)
	 	{
	 		if(res[i].get_dated().date_aujrd()==true)
	 		{
	 			rr[nn]=res[i];
	 			nn++;
			}
		}
		return rr;
	 }
	 reservation * res_expi_aujrd(reservation res[200],int n,int &nn)
	 {
	 	reservation *rr=new reservation[50];
	 	nn=0;
	 	for(int i=0;i<n;i++)
	 	{
	 		if(res[i].get_datef().date_aujrd()==true)
	 		{
	 			rr[nn]=res[i];
	 			nn++;
			}
		}
		return rr;
	 }
	 void annul_res_exp(reservation res[200],int n)
	 {
	 	for(int i=0;i<n;i++)
	 	{
	 		if(res[i].get_datef().date_aujrd()==true)
	 		{
	 			if(res[i].get_etatr()==1)
	 			{
	 				res[i].etat_reserv();
				}
	 			
			}
		}
	 }
	 
//dureee
   date dr;//dr.a=v
	void moina(date dd,date ddd)//dd fin ddd debut dr resultat globale
	{
		int v;
		v=dd.get_a()-ddd.get_a();
		dr.set_a(v);
		
	}
	void moinm(date dd,date ddd)
	{
		int v;
		v=dd.get_m()-ddd.get_m();
		if(v<0)
		{
			v=v+12;
			dr.set_m(v);
			date d1;
			moina(dr,d1);
		}
		else
		dr.set_m(v);
	}
	void moinj(date dd,date ddd)
	{
		int v;
		v=dd.get_j()-ddd.get_j();
		if(v<0)
		{
			if(ddd.get_m()==1||ddd.get_m()==3||ddd.get_m()==5||ddd.get_m()==7||ddd.get_m()==8||ddd.get_m()==10||ddd.get_m()==12)
			{
				v=v+31;
			}
			else if(ddd.get_m()==4||ddd.get_m()==6||ddd.get_m()==9||ddd.get_m()==11)
			{
				v=v+30;
			}
			else if(ddd.get_m()==2 && (ddd.get_a()%4==0&&ddd.get_a()%100!=0||ddd.get_a()%400==0))
			{
				v=v+29;
			}
			else
			{ 
			    v=v+28;
			}
			dr.set_j(v);
			date d1;
			moinm(dr,d1);
		}
		else 
		dr.set_j(v);

	}

	  
	void reservation::duree_res()
	{
		moina(d_fin,d_debut);
		moinm(d_fin,d_debut);
		moinj(d_fin,d_debut);
		cout<<dr.get_a()<<" annees "<<dr.get_m()<<" mois "<<dr.get_j()<<" jours";
	}
	
	int main() {
	reservation res[200];//principal
	int n=0;//nombre reservation principal
	reservation *rrr;
	chambre ch1;
	client cc;
	int nn;
	int choix1,choix2;
	int idr,test,idch,idc;
	reservation rr;
	// MENUU
	do{
	cout<<"-----------------------------MENU PRINCIPAL------------------------------"<<endl;
	cout<<"     |    1- Reservation                                          |"<<endl;
	cout<<"     |    2- Chambre                                              |"<<endl;
	cout<<"     |    3- Client                                               |"<<endl;
	cout<<"     |    0- Sortir du programme                                  |"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl<<endl;
    
    do{
    cout<<"***Entrer votre choix***:";
    cin>>choix1;
    }while(choix1>3 || choix1<0);
    
    switch(choix1)
    {
    	case 1:{
    		do{
    		cout<<"----------------------------MENU RESERVATION-----------------------------"<<endl;
	        cout<<"     |  1- Ajouter une reservation                                |"<<endl;
	        cout<<"     |  2- Afficher les informations de toutes les reservations   |"<<endl;
	        cout<<"     |  3- Supprimer une reservation                              |"<<endl;
	        cout<<"     |  4- Calculer la duree d'une reservation                    |"<<endl;
	        cout<<"     |  5- Afficher une reservation donner par un id              |"<<endl;
	        cout<<"     |  6- Modifier l'etat de la reservation                      |"<<endl;
	        cout<<"     |  7- Afficher toutes les reservation effectuer aujourd'hui  |"<<endl;
	        cout<<"     |  8- Afficher toutes les reservation expirer aujourd'hui    |"<<endl;
	        cout<<"     |  9- Annuler les reservations qui seront expirés aujourd'hui|"<<endl;
	        cout<<"     |  0- Retourner au menu principal                            |"<<endl;
            cout<<"-------------------------------------------------------------------------"<<endl<<endl;
            do{
            cout<<"***Entrer votre choix***:";
            cin>>choix2;
            }while(choix2>9 || choix2<0);
            
            switch(choix2)
            {
            	case 1:{
            		ajout_reserv(res,n);
					break;
				}
				case 2:{
					affich_tout_res(res,n);
					break;
				}
				case 3:{
					cout<<"Entrer l'id de la reservation a supprimer";
					cin>>idr;
					rr.set_idr(idr);
					supp_reserv(res,n,rr);
					break;
				}
				case 4:{
					cout<<"Entrer l'id de la reservation pour calculer sa duree";
					cin>>idr;
					rr.set_idr(idr);
					test=test_si_reserve_eff(rr,res,n);
					if(test==-1)
					{
						cout<<"Cette reservation n'existe pas"<<endl;
					}
					else
					{
						res[test].duree_res();
						cout<<endl;
					}
					break;
				}
				case 5:{
					cout<<"Entrer l'id de la reservation a afficher";
					cin>>idr;
					rr.set_idr(idr);
					test=test_si_reserve_eff(rr,res,n);
					if(test==-1)
					{
						cout<<"Cette reservation n'existe pas"<<endl;
					}
					else
					{
						res[test].affiche_reserv();
					}					
					
					break;
				}
				case 6:{
					cout<<"Entrer l'id de la reservation dont vous voulez changer d'etat";
					cin>>idr;
					rr.set_idr(idr);
					test=test_si_reserve_eff(rr,res,n);
					if(test==-1)
					{
						cout<<"Cette reservation n'existe pas"<<endl;
					}
					else
					{
						res[test].etat_reserv();
					}	
					
					break;
				}
				case 7:{
					rrr=res_eff_aujrd(res,n,nn);
					for(int j=0;j<nn;j++)
					{
						rrr[j].affiche_reserv();
						cout<<endl;
					}
					break;
				}
				case 8:{
					rrr=res_expi_aujrd(res,n,nn);
					for(int j=0;j<nn;j++)
					{
						rrr[j].affiche_reserv();
						cout<<endl;
					}
					break;
				}
				case 9:{
					annul_res_exp(res,n);
					break;
				}
				
			}
			}while(choix2!=0);
    		
			break;
		}
		case 2:{
			do{
			cout<<"------------------------------MENU CHAMBRE-------------------------------"<<endl;
	        cout<<"     |  1- Ajouter une chambre a une reservation                  |"<<endl;
	        cout<<"     |  2- Supprimer une chambre d'une reservation                |"<<endl;
	        cout<<"     |  3- Modifier une chambre d'une reservation                 |"<<endl;
	        cout<<"     |  0- Retourner au menu principal                            |"<<endl;
            cout<<"-------------------------------------------------------------------------"<<endl<<endl;
			do{
            cout<<"***Entrer votre choix***:";
            cin>>choix2;
            }while(choix2>3 || choix2<0);
            switch(choix2)
            {
            	case 1:{
					cout<<"Entrer l'id de la reservation ou vous voulez ajouter une chambre";
					cin>>idr;
					rr.set_idr(idr);
					test=test_si_reserve_eff(rr,res,n);
					if(test==-1)
					{
						cout<<"Cette reservation n'existe pas"<<endl;
					}
					else
					{
						res[test].ajout_ch_res();
					}	            		
					break;
				}
				case 2:{
					cout<<"Entrer l'id de la reservation ou se trouvre la chambre que vous voulez supprimer";
					cin>>idr;
					rr.set_idr(idr);
					test=test_si_reserve_eff(rr,res,n);
					if(test==-1)
					{
						cout<<"Cette reservation n'existe pas"<<endl;
					}
					else
					{
					    cout<<"Entrer l'id de la chambre a supprimer ";
					    cin>>idch;
						ch1.Set_code(idch);
						res[test].supp_ch(ch1);
					}	       
					
					break;
				}
				case 3:{
					cout<<"Entrer l'id de la reservation ou se trouve la chambre a modifier";
					cin>>idr;
					rr.set_idr(idr);
				    cout<<"Entrer l'id de la chambre a modifier ";
					cin>>idch;
					ch1.Set_code(idch);
					modifier_ch(rr,ch1,res,n);
					break;
				}
			}
			}while(choix2!=0);
			break;
		}
		case 3:{
			do{
			cout<<"------------------------------MENU CLIENT--------------------------------"<<endl;
	        cout<<"     |  1- Afficher un client par son id                          |"<<endl;
	        cout<<"     |  2- Afficher tout les client                               |"<<endl;
	        cout<<"     |  0- Retourner au menu principal                            |"<<endl;
            cout<<"-------------------------------------------------------------------------"<<endl<<endl;
            do{
            cout<<"***Entrer votre choix***:";
            cin>>choix2;
            }while(choix2>2 || choix2<0);
            switch(choix2)
            {
            	case 1:{
            		cout<<"Entrer l'id du client ";
					cin>>idc;
					cc.Set_id(idc);
            		test=test_si_client_reserve(cc,res,n);
            		if(test==-1)
            		{
            			cout<<"Ce client n'a jamais effectue une reservation"<<endl;
					}
					else
					{
						res[test].get_cli().Affich_c();
					}
					break;
				}
				case 2:{
					if(n==0)
					{
						cout<<"Il n'existe aucun client"<<endl;
					}
					for(int j=0;j<n;j++)
					{
						res[j].get_cli().Affich_c();
						cout<<endl;
					}
					break;
				}
			}
            }while(choix2!=0);
			break;
		}
    	
	}
    
	}while(choix1 !=0);
	
	
}
