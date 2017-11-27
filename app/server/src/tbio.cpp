#include "tbio.h"
#include "dblogin.h"

TBTESTIO::TBTESTIO(const int id, const char *buf){


}
//
void TBTESTIO::Set(){
    m_id = id;
    strcpy(m_buf, buf);
}

void TBTESTIO::SetField(){
     
     DBConnect();
}

void TBTESTIO::GetField(){
    DBConnect();

}
