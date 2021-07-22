//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef NODES_MEC_MEPLATFORM_SERVICEREGISTRY_H_
#define NODES_MEC_MEPLATFORM_SERVICEREGISTRY_H_

#include <omnetpp.h>
#include "nodes/mec/MEPlatform/MeServices/MeServiceBase/MeServiceBase.h"
#include "inet/networklayer/common/L3Address.h"
#include "nodes/binder/LteBinder.h"
#include "nodes/mec/MecCommon.h"
#include "nodes/mec/MEPlatform/ServiceRegistry/resources/ServiceInfo.h"
#include <map>

typedef std::map<const std::string, ServiceInfo> MecServicesMap;

class ServiceRegistry: public MeServiceBase
{
private:
    // key serviceName

    //MecServicesMap mecServices_;
    std::set<std::string> omnetServices_;
    std::vector<ServiceInfo> mecServices_;
    //LteBinder (oracle module)
    LteBinder* binder_;

    //parent modules
    omnetpp::cModule* mePlatform;
    omnetpp::cModule* meHost;

    std::string uuidBase;
    int servIdCounter;
public:
    ServiceRegistry();
    virtual ~ServiceRegistry();

    void registerMeService(const ServiceDescriptor& servDesc);
    SockAddr retrieveMeService(const std::string& MeServiceName);
    const std::vector<ServiceInfo>* getAvailableMecServices() const;
    const std::set<std::string>* getAvailableOmnetServices() const;

protected:

    void initialize(int stage) override;

    void handleStartOperation(inet::LifecycleOperation *operation) override;

    virtual void handleGETRequest(const HttpRequestMessage *currentRequestMessageServed, inet::TcpSocket* socket) override;
    virtual void handlePOSTRequest(const HttpRequestMessage *currentRequestMessageServed, inet::TcpSocket* socket)   override;
    virtual void handlePUTRequest(const HttpRequestMessage *currentRequestMessageServed, inet::TcpSocket* socket)    override;
    virtual void handleDELETERequest(const HttpRequestMessage *currentRequestMessageServed, inet::TcpSocket* socket) override;


};


#endif /* NODES_MEC_MEPLATFORM_SERVICEREGISTRY_H_ */
