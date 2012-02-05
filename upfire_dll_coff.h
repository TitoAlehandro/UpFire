#ifndef UPFIRE_DLL_COFF_H
#define UPFIRE_DLL_COFF_H
#endif
#ifndef WINAPI
  #define WINAPI
#endif

#include "UPFire_DLL_coff_global.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "windows.h"
#define _WIN32_WINNT 0x0501

#include <ndisapi_qt.h>

#define FILTR_COUNT 100
#define RULES_COUNT 100
#define SIZE_NAME   256


//Class implements the filtr of firewall
class UPFIRE_DLL_COFFSHARED_EXPORT UPFire_DLL_coff {
public:
    UPFire_DLL_coff();
    int StrToInt_protocol(char *Name_Protocol);
    int IntToStr_protocol(int   Number_Protocol,
                          char *Name_Protocol);

};
//Structure of IP adress
typedef struct _IP_ADDR{
      int ip1;
      int ip2;
      int ip3;
      int ip4;
    } IP_ADDR, *PIP_ADDR;

typedef struct _PORT{
  int  SourcePortBegin;        // Source port begin
  int  DestPortBegin;          // Destination port begin
  int  SourcePortEnd;          // Source port end
  int  DestPortEnd;            // Destination port end
  int  TypePort;               /* Type of port(
                                  0 - default
                                  1 - one value SourcePort
                                  2 - range SourcePort
                                  3 - one value DestPort
                                  4 - range DestPort
                                  )
                               */
}PORT, *PPORT;


typedef struct _PROTOCOL{
  int  NumberProtocol;         // Number of protocol (iphlp.h)
}PROTOCOL, *PPROTOCOL;


typedef struct _IP{
  IP_ADDR  SourceIP;           // Source port
  IP_ADDR  DestIP;             // Destination port
  int      TypeIP;             // Type of IP(0 - default, 1 - one value, 2 - range)
} IP, *PIP;

class UPFIRE_DLL_COFFSHARED_EXPORT CFiltr
  {
  public:  
    CFiltr(){
      memset(this, 0, sizeof(CFiltr));
    }


    long        put_DestIP_ToStr      (/*__out*/ char   *str);
    long        put_SourceIP_ToStr    (/*__out*/ char   *str);
    long        put_DestIP            (/*__out*/ IP_ADDR*p_struct_ip);
    long        put_SourceIP          (/*__out*/ IP_ADDR*p_struct_ip);

    long        set_IP                (PIP p_ip);
    long        set_DestIP_FromStr    (/*__in*/  char   *str);
    long        set_SourceIP_FromStr  (/*__in*/  char   *str);
    long        set_IP_FromStr        (/*__in*/  char   *str);
    long        set_DestIP            (/*__out*/ IP_ADDR*p_struct_ip);
    long        set_SourceIP          (/*__out*/ IP_ADDR*p_struct_ip);

    long        set_protocol_FromStr  (/*__in*/  char *Name_Protocol);
    long        set_protocol          (/*__in*/  PPROTOCOL  p_protocol);


    long        set_Port              (/*__in*/   PPORT  p_port);
    long        set_DestPort          (/*__in*/   int    PortBegin,
                                       /*__in*/   int    PortEnd,
                                       /*__in*/   int    TypePort);
    long        set_SourcePort        (/*__in*/   int    PortBegin,
                                       /*__in*/   int    PortEnd,
                                       /*__in*/   int    TypePort);
    long        set_Port_FromStr      (/*__in*/   char  *PortStr,
                                       /*__in*/   int    TypePort);

    long        set_type_packet       (/*__in*/   int    Type_Packet);
    long        set_type_action       (/*__in*/   int    Type_Action);
    long        set_FiltrType         (/*__in*/   long   Filtr_Type);
    long        set_Numb_Filtr        (/*__in*/   long   NumbFiltr);
    long        set_Name_of_Filtr     (/*__in*/   char  *Name_of_Filtr);
    long        set_Name_of_Process   (/*__in*/   char  *Name_of_process);
    long        set_PID_of_Process    (/*__in*/   long   PID_of_process);



    long        add_to_adapter        (/*__in*/   STATIC_FILTER_TABLE *pAdapterFilters);

    long        get_Numb_Filtr        ();
    int         get_type_packet       ();
    int         get_type_action       ();
    long        get_FiltrType         ();
    char       *get_Name_of_Filtr     ();


    PORT       *get_Port              ();
    PROTOCOL   *get_Protocol          ();
    int         get_TypePort          ();
    int         get_DestPort          (PORT port);
    int         get_SourcePort        (PORT port);

    int         get_Type_IP           ();
    IP         *get_IP                ();

    char       *get_Name_of_Process   ();
    int         get_PID_of_Process    ();

    int         get_procc_count       (char *Name);
    int         set_port_lst          (int  *list,
                                       int   numb,
                                       char *Name);



  private:
    int         type_packet;       // Type of packet (0 - entering, 1 - outgoing, 2 - entering and outgoing)
    int         type_action;       // Type of action (0 - default, 1 - redirect, 2 - block)
    long        FiltrType;         // Type of filter:
                                   // 1 - Restriction on the port
                                   // 2 - Restriction on the protocol
                                   // 3 - Restriction on the ip adress
                                   // 4 - Restriction on the open access
                                   // 5 - Restriction on the close access
    long        Numb_Filtr;        // Number of filtr
    char        Name_of_Filtr[SIZE_NAME];       // Name of filtr
    char        Name_of_Process[SIZE_NAME];     // Name of Process
    long        PID_of_Process;                 // PID of Process


    PORT        port_;
    PROTOCOL    protocol_;
    IP          ip_;

  };

//Class implements the rule of filtration
class UPFIRE_DLL_COFFSHARED_EXPORT CRule
  {
  public:
    CRule(){
      memset(this, 0, sizeof(CRule));
      enabled = false;
    }

    long   add_filtr           (CFiltr *pfiltr);
    long   change_filtr        (CFiltr *pfiltr);
    CFiltr*get_filtr_lst       ();

    //long   get_Numb_Rule       ();
    int    get_Size_Rule       ();
    char  *get_Name_of_Rule    ();
    int    get_enabled         ();

    int  set_enable          (int enable);
    long set_Size_of_Rule    (long SizeOfRule);
    //long set_Numb_Rule       (long Numb_of_Rule);
    long set_Name_of_Rule    (char*Name_of_Rule);
  private:
    CFiltr      fltr_lst[FILTR_COUNT];     // List of Filters
    long        Size_of_Rule;      // Size of Rule.(Number of Filters contain in Rule)
    //long        Numb_Rule;         // Number of Rule
    char        Name_of_Rule[256]; // Name of Rule
    int         enabled;


  };

//Class implements the global settings of firewall
class UPFIRE_DLL_COFFSHARED_EXPORT CWall
  {
  public:
    CWall() {
      Size_of_Wall = 0;

      // Allocate table filters for 10 filters

      DWORD dwTableSize = sizeof(STATIC_FILTER_TABLE) + sizeof(STATIC_FILTER)*100;
      pFilters = (PSTATIC_FILTER_TABLE)malloc(dwTableSize);
      memset (pFilters, 0, dwTableSize);
      bSetPromisc = FALSE;
      dwFilter = 0;
    }
    ~CWall() {
      st_ReleaseInterface();
      free(pFilters);
    }

    long   add_rule          (CRule *pRule);
    long   del_rule          (/*__in*/ CRule *pRule);
    long   change_rule       (CRule *pRule);
    long   set_rules         (DWORD numb_adapt);
    long   set_enable        (/*__in*/ int Number_Rule,
                              /*__in*/ int Value);
    long   set_Size_Wall     (/*__in*/ int Size_Wall);

    long   get_NumbRule_from_Name(/*__in*/ char *Name_of_Rule);
    unsigned long        get_adapt_count    ();
    CRule               *get_rule_lst       ();
    int                  get_Size_Wall      ();

    BOOL                *get_bSetPromisc    ();
    CNdisApi            *get_api            ();
    TCP_AdapterList     *get_AdaptList      ();
    DWORD               *get_iIndex         ();
    DWORD               *get_dwFilter       ();
    STATIC_FILTER_TABLE *get_pFilters       ();



  private:
    CRule      rules_lst[RULES_COUNT];    // List of Rules
    long       Size_of_Wall;              // Size of Wall.(Number of Rules contain in Wall)
    CNdisApi                api;
    TCP_AdapterList         AdaptList;
    DWORD                   iIndex;
    BOOL                    bSetPromisc;
    DWORD                   dwFilter;
    PSTATIC_FILTER_TABLE    pFilters;
    void                    st_ReleaseInterface();
    void                    ReleaseInterface();
  };
