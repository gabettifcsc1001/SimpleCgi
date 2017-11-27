include "tbio.h"
include "dblogin.h"

TBTESTIO::TBTESTIO(const int id, const char buf){


}

void TBTESTIO::Set(){
    m_id = id;
    m_buf = buf;
}

void TVTESTIO::SetField(){

}

void TBTESTIO::GetField(){
    DBConnect();

}
