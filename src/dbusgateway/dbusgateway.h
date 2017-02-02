#ifndef DBUSGATEWAY_H_
#define DBUSGATEWAY_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/org/genivi/SotaClientStubDefault.hpp>
#include <v1/org/genivi/SoftwareLoadingManagerProxy.hpp>

#include "commands.h"
#include "events.h"
#include "gateway.h"
#include "config.h"
using namespace v1::org::genivi;


class DbusGateway: public v1::org::genivi::SotaClientStubDefault, public Gateway {
public:
    DbusGateway(const Config& config_in, command::Channel *command_channel_in);
    virtual ~DbusGateway();
    virtual void processEvent(const boost::shared_ptr<event::BaseEvent> &event);
    /**
     * description: Sent by SC to start the download of an update previously announced
        as
     *   available through an update_available() call made from SC to
        SWLM.
     */
    virtual void initiateDownload(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _updateId, initiateDownloadReply_t _reply);
    /**
     * description: Abort a download previously initiated with initiate_download().
        Invoked by
     *   SWLM in response to an error or an explicit
        request sent by HMI to SWLM in
     *   response to a user abort.
     */
    virtual void abortDownload(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _updateId, abortDownloadReply_t _reply);
    /**
     * description: Receive an update report from SWLM with the processing result of all
        bundled
     *   operations.
        An update report message can either be sent in response
        to an
     *   downloadComplete() message transmitted from SC to SWLM,
        or be sent
     *   unsolicited by SWLM to SC
     */
    virtual void updateReport(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _updateId, std::vector<v1::org::genivi::SotaClient::OperationResult> _operationsResults, updateReportReply_t _reply);
    void run();
private:
    command::Channel *command_channel;
    std::thread *thread;
    void process_events();
    std::shared_ptr<SoftwareLoadingManagerProxy<> > swlm;



};
#endif /* DBUSGATEWAY_H_ */
