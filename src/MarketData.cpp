#include "MarketData.h"

MarketData::MarketData():mdapi(nullptr){
    mdapi = CThostFtdcMdApi::CreateFtdcMdApi();
    mdapi -> RegisterSpi(this);
    mdapi -> RegisterFront((char*)"");
    mdapi -> Init();
    mdapi -> Join();
    mdapi -> Release();
}

void MarketData::OnFrontConnected(){
    printf("connected");
    CThostFtdcReqUserLoginField t{};
    strcpy(t.BrokerID, "");
    strcpy(t.UserID,"");
    strcpy(t.Password,"");

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
