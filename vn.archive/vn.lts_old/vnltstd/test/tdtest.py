# encoding: UTF-8

import sys
from time import sleep

from PyQt4 import QtGui

from vnltstd import *
from lts_data_type import defineDict

#----------------------------------------------------------------------
def print_dict(d):
    """按照键值打印一个字典"""
    for key,value in d.items():
        print key + ':' + str(value)
        
        
#----------------------------------------------------------------------
def simple_log(func):
    """简单装饰器用于输出函数名"""
    def wrapper(*args, **kw):
        print ""
        print str(func.__name__)
        return func(*args, **kw)
    return wrapper


########################################################################
class TestTdApi(TdApi):
    """测试用实例"""

    #----------------------------------------------------------------------
    def __init__(self):
        """Constructor"""
        super(TestTdApi, self).__init__()
        
    #----------------------------------------------------------------------
    @simple_log    
    def onFrontConnected(self):
        """服务器连接"""
        pass
    
    #----------------------------------------------------------------------
    @simple_log    
    def onFrontDisconnected(self, n):
        """服务器断开"""
        print n
        
    #----------------------------------------------------------------------
    @simple_log    
    def onHeartBeatWarning(self, n):
        """心跳报警"""
        print n
    
    #----------------------------------------------------------------------
    @simple_log    
    def onRspError(self, error, n, last):
        """错误"""
        print_dict(error)
    
    #----------------------------------------------------------------------
    @simple_log  
    def onRspUserLogin(self, data, error, n, last):
        """登陆回报"""
        print_dict(data)
        print_dict(error)
        self.brokerID = data['BrokerID']
        self.userID = data['UserID']
        self.frontID = data['FrontID']
        self.sessionID = data['SessionID']
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspUserLogout(self, data, error, n, last):
        """登出回报"""
        print_dict(data)
        print_dict(error)
    
    #----------------------------------------------------------------------
    @simple_log    
    def onRspOrderInsert(self, data, error, n, last):
        """发单错误（柜台）"""
        print_dict(data)
        print_dict(error)       
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspOrderAction(self, data, error, n, last):
        """撤单错误（柜台）"""
        print_dict(data)
        print_dict(error)

    #----------------------------------------------------------------------
    @simple_log    
    def onRspUserPasswordUpdate(self, data, error, n, last):
        """用户密码更新错误"""
        print_dict(data)
        print_dict(error)

    #----------------------------------------------------------------------
    @simple_log    
    def onRspTradingAccountPasswordUpdate(self, data, error, n, last):
        """交易账户密码更新错误"""
        print_dict(data)
        print_dict(error)

    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryExchange(self, data, error, n, last):
        """交易所查询回报"""
        print_dict(data)
        print_dict(error)

    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryInstrument(self, data, error, n, last):
        """合约查询回报"""
        if len(data['InstrumentID']) == 8 and '510180' in data['ExchangeInstID']:
            print_dict(data)
            print_dict(error)
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryInvestor(self, data, error, n, last):
        """投资者查询回报"""
        print_dict(data)
        print_dict(error)
    
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryTradingCode(self, data, error, n, last):
        """交易编码查询回报"""
        print_dict(data)
        print_dict(error)
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryTradingAccount(self, data, error, n, last):
        """资金账户查询回报"""
        print_dict(data)
        print_dict(error)
        self.accountID = data['AccountID']
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryDepthMarketData(self, data, error, n, last):
        """行情查询回报"""
        print_dict(data)
        print_dict(error)
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryBondInterest(self, data, error, n, last):
        """债券利息查询回报"""
        print_dict(data)
        print_dict(error)
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryMarketRationInfo(self, data, error, n, last):
        """市值配售查询回报"""
        print_dict(data)
        print_dict(error)
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryInstrumentCommissionRate(self, data, error, n, last):
        """合约手续费查询回报"""
        print_dict(data)
        print_dict(error)

    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryETFInstrument(self, data, error, n, last):
        """ETF基金查询回报"""
        print_dict(data)
        print_dict(error)

    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryETFBasket(self, data, error, n, last):
        """ETF股票篮查询回报"""
        print_dict(data)
        print_dict(error)

    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryOFInstrument(self, data, error, n, last):
        """OF合约查询回报"""
        print_dict(data)
        print_dict(error)
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQrySFInstrument(self, data, error, n, last):
        """SF合约查询回报"""
        print_dict(data)
        print_dict(error)
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryOrder(self, data, error, n, last):
        """报单查询回报"""
        print_dict(data)
        print_dict(error)    
    
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryTrade(self, data, error, n, last):
        """成交查询回报"""
        print_dict(data)
        print_dict(error)    

    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryInvestorPosition(self, data, error, n, last):
        """持仓查询回报"""
        print_dict(data)
        print_dict(error)

    #----------------------------------------------------------------------
    @simple_log    
    def onRtnOrder(self, data):
        """报单回报"""
        print_dict(data)
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRtnTrade(self, data):
        """成交回报"""
        print_dict(data)
        
    #----------------------------------------------------------------------
    @simple_log    
    def onErrRtnOrderInsert(self, data, error):
        """发单错误回报（交易所）"""
        print_dict(data)
        print_dict(error)
        
    #----------------------------------------------------------------------
    @simple_log    
    def onErrRtnOrderAction(self, data, error):
        """撤单错误回报（交易所）"""
        print_dict(data)
        print_dict(error)
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspFundOutByLiber(self, data, error, n, last):
        """LTS发起出金应答"""
        print_dict(data)
        print_dict(error)    
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRtnFundOutByLiber(self, data):
        """LTS发起出金通知"""
        print_dict(data)    
        
    #----------------------------------------------------------------------
    @simple_log    
    def onErrRtnFundOutByLiber(self, data, error):
        """LTS发起出金错误回报"""
        print_dict(data)
        print_dict(error)    
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRtnFundInByBank(self, data):
        """银行发起入金通知"""
        print_dict(data)     
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryFundTransferSerial(self, data, error, n, last):
        """资金转账查询应答"""
        print_dict(data)
        print_dict(error)    
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRspFundInterTransfer(self, data, error, n, last):
        """资金内转应答"""
        print_dict(data)
        print_dict(error)      
      
    #----------------------------------------------------------------------
    @simple_log    
    def onRspQryFundInterTransferSerial(self, data, error, n, last):
        """资金内转流水查询应答"""
        print_dict(data)
        print_dict(error)      
        
    #----------------------------------------------------------------------
    @simple_log    
    def onRtnFundInterTransferSerial(self, data):
        """资金内转流水通知"""
        print_dict(data)   
        
    #----------------------------------------------------------------------
    @simple_log    
    def onErrRtnFundInterTransfer(self, data, error):
        """资金内转错误回报"""
        print_dict(data)
        print_dict(error)        
        
        
        
#----------------------------------------------------------------------
def main():
    """主测试函数，出现堵塞时可以考虑使用sleep"""
    reqid = 0
    
    # 创建Qt应用对象，用于事件循环
    app = QtGui.QApplication(sys.argv)

    # 创建API对象，测试通过
    api = TestTdApi()
    
    # 在C++环境中创建MdApi对象，传入参数是希望用来保存.con文件的地址，测试通过
    api.createFtdcTraderApi('')
    
    # 设置数据流重传方式，测试通过
    api.subscribePrivateTopic(1)
    api.subscribePublicTopic(1)
    
    # 注册前置机地址，测试通过
    api.registerFront("tcp://211.144.195.163:34505")
    
    # 初始化api，连接前置机，测试通过
    api.init()
    sleep(0.5)
    
    # 登陆，测试通过
    loginReq = {}                           # 创建一个空字典
    loginReq['UserID'] = ''                 # 参数作为字典键值的方式传入
    loginReq['Password'] = ''               # 键名和C++中的结构体成员名对应
    loginReq['BrokerID'] = ''    
    reqid = reqid + 1                       # 请求数必须保持唯一性
    i = api.reqUserLogin(loginReq, reqid)
    sleep(0.5)
    
    ## 登出，测试通过
    #reqid = reqid + 1
    #i = api.reqUserLogout({}, 1)
    #sleep(0.5)
    
    ## 安全退出，测试通过
    #i = api.exit()
    
    ## 获取交易日，目前输出为空，测试通过
    #day = api.getTradingDay()
    #print 'Trading Day is:' + str(day)
    #sleep(0.5)
    
    ##########################################################
    ## 查询交易所，测试通过
    #reqid = reqid + 1
    #i = api.reqQryExchange({}, reqid)
    
    ## 查询合约列表，测试通过
    #reqid = reqid + 1
    #i = api.reqQryInstrument({}, reqid)
    
    ## 查询投资者，测试通过
    #reqid = reqid + 1
    #i = api.reqQryInvestor({}, reqid)
    
    ## 查询交易编码，测试通过
    #reqid = reqid + 1
    #i = api.reqQryTradingCode({}, reqid)
    
    ## 查询交易账户，测试通过
    #reqid = reqid + 1
    #i = api.reqQryTradingAccount({}, reqid)
    #sleep(1.0)
    
    ## 查询行情, 测试失败，C++环境中返回空指针
    #reqid = reqid + 1
    #req = {}
    #req['InstrumentID'] = '600000'
    #i = api.reqQryDepthMarketData(req, reqid)
    
    ## 查询债券利率，测试通过
    #reqid = reqid + 1
    #i = api.reqQryBondInterest({}, reqid)
    
    ## 查询市值配售，测试无反应
    #reqid = reqid + 1
    #i = api.reqQryMarketRationInfo({}, reqid)
    
    ## 查询手续费率, 测试失败，C++环境中返回空指针
    #reqid = reqid + 1
    #req = {}
    #req['InstrumentID'] = '600000'
    #req['ExchangeID'] = 'SSE'
    #req['InvestorID'] = api.userID
    #req['BrokerID'] = api.brokerID
    #i = api.reqQryInstrumentCommissionRate(req, reqid)
    
    ## 查询ETF合约，测试通过
    #reqid = reqid + 1
    #i = api.reqQryETFInstrument({}, reqid)    

    ## 查询ETF组合，测试通过
    #reqid = reqid + 1
    #i = api.reqQryETFBasket({}, reqid)

    ## 查询OF合约，测试通过
    #reqid = reqid + 1
    #i = api.reqQryOFInstrument({}, reqid)    

    ## 查询SF合约，测试通过
    #reqid = reqid + 1
    #i = api.reqQrySFInstrument({}, reqid)      
    
    ######################################################
    # 以下三个未测试
    ## 查询发单, 测试通过
    #reqid = reqid + 1
    #req = {}
    #req['BrokerID'] = api.brokerID
    #req['InvestorID'] = api.userID
    #i = api.reqQryOrder(req, reqid)
    #sleep(2.0)
    
    ## 查询成交, 测试通过
    #reqid = reqid + 1
    #req = {}
    #req['BrokerID'] = api.brokerID
    #req['InvestorID'] = api.userID    
    #i = api.reqQryTrade(req, reqid)
    #sleep(2.0)
    
    ## 查询持仓，测试通过
    #reqid = reqid + 1
    #req = {}
    #req['BrokerID'] = api.brokerID
    #req['InvestorID'] = api.userID    
    #i = api.reqQryInvestorPosition(req, reqid)
    #sleep(2.0)
    
    ################################################
    ## 更新行情密码，测试通过
    #reqid = reqid + 1
    #req = {}
    #req['UserID'] = api.userID
    #req['BrokerID'] = api.brokerID
    #req['NewPassword'] = "624001X"
    #req['OldPassword'] = "624001X"
    #i = api.reqUserPasswordUpdate(req, reqid)

    ## 更新交易密码，测试有反应，但报错
    ## 应当无需更新，因为登陆直接使用user密码
    ## 获取api.accountID需要先查询交易账户reqQryTradingAccount
    #reqid = reqid + 1
    #req = {}
    #req['AccountID'] = api.accountID
    #req['BrokerID'] = api.brokerID
    #req['NewPassword'] = "624001X"
    #req['OldPassword'] = "624001X"
    #i = api.reqTradingAccountPasswordUpdate(req, reqid)    

    ################################################
    ## 发单测试, 测试通过
    #reqid = reqid + 1
    #req = {}
    #req['InvestorID'] = api.userID
    #req['UserID'] = api.userID
    #req['BrokerID'] = api.brokerID
    #req['InstrumentID'] = '11000061'
    #req['ExchangeID'] = 'SSE'
    #req['OrderPriceType'] = defineDict['SECURITY_FTDC_OPT_LimitPrice']
    #req['LimitPrice'] = '0.1850'
    #req['VolumeTotalOriginal'] = 1
    #req['Direction'] = defineDict['SECURITY_FTDC_D_Buy']
    #req['CombOffsetFlag'] = defineDict['SECURITY_FTDC_OF_Open']
    #req['OrderRef'] = '1'    
    #req['CombHedgeFlag'] = defineDict['SECURITY_FTDC_HF_Speculation']
    #req['ContingentCondition'] = defineDict['SECURITY_FTDC_CC_Immediately']
    #req['ForceCloseReason'] = defineDict['SECURITY_FTDC_FCC_NotForceClose']
    #req['IsAutoSuspend'] = 0
    #req['UserForceClose'] = 0
    #req['TimeCondition'] = defineDict['SECURITY_FTDC_TC_GFD']
    #req['VolumeCondition'] = defineDict['SECURITY_FTDC_VC_AV']
    #req['MinVolume'] = 1
    #i = api.reqOrderInsert(req, reqid)
    #sleep(1.0)
    
    ## 撤单测试，测试通过
    #reqid = reqid + 1
    #req = {}
    #req['InstrumentID'] = '11000061'
    #req['ExchangeID'] = 'SSE'
    #req['OrderRef'] = '1'
    #req['ActionFlag'] = defineDict['SECURITY_FTDC_AF_Delete']
    #req['BrokerID'] = api.brokerID
    #req['InvestorID'] = api.userID
    #req['FrontID'] = api.frontID
    #req['SessionID'] = api.sessionID
    #i = api.reqOrderAction(req, reqid)
    
    ################################################
    ## 测试资金转出，未测试
    #reqid = reqid + 1
    #i = api.reqFundOutByLiber({}, reqid)
    
    ## 测试资金内转，未测试
    #reqid = reqid + 1
    #i = api. reqFundInterTransfer({}, reqid)    
    
    ## 测试查询账户转账流水，未测试
    #reqid = reqid + 1
    #i = api.reqQryFundTransferSerial({}, reqid)
    
    ## 测试查询内部账户转账流水，未测试
    #reqid = reqid + 1
    #i = api.reqQryFundInterTransferSerial({}, reqid)
    
    
    
    
    
    # 连续运行
    app.exec_()
    
    
    
if __name__ == '__main__':
    main()
