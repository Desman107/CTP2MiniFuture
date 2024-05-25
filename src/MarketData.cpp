#include "MarketData.h"

MarketData::MarketData():mdapi(nullptr){
    mdapi = CThostFtdcMdApi::CreateFtdcMdApi();
    mdapi -> RegisterSpi(this);
    mdapi -> RegisterFront((char*)"tcp://180.168.146.187:10131");
    mdapi -> Init();
    mdapi -> Join();
    mdapi -> Release();
}

void MarketData::OnFrontConnected(){
    printf("connected");
    CThostFtdcReqUserLoginField t{};
    strcpy(t.BrokerID, "9999");
    strcpy(t.UserID,"226478");
    strcpy(t.Password,"792@Qq&com");

    int rtn = mdapi -> ReqUserLogin(&t,++nReqID);
    printf("%d",rtn);
    
}

void MarketData::OnFrontDisconnected(int nReason){
    printf("disconnected");

}

void MarketData::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    if (pRspInfo != nullptr && pRspInfo->ErrorID != 0){
        printf("ErrorID = %d ErrorMsg = %s\n", pRspInfo ->ErrorID,pRspInfo ->ErrorMsg);
        return;
    }
    printf("Login succeeded");
}
void MarketData::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    
}
void MarketData::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData){
    
}

MarketData::~MarketData(){

}
