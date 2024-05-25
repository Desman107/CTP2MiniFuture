#ifndef MARKET_DATA
#define MARKET_DATA

#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
#include <vector>
#include "ThostFtdcMdApi.h"

class MarketData : public CThostFtdcMdSpi {
public:
    MarketData();
    ~MarketData();
public:
    void OnFrontConnected();
    void OnFrontDisconnected(int nReason);
    void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
public:
    CThostFtdcMdApi* mdapi;
    // BrokerInfo bi;
    int nReqID = 0;
};

#endif // MARKET_DATA
