#pragma once

#include "dds/DCPS/Service_Participant.h"

class AppConfig {
public:
  static const OpenDDS::DCPS::RepoId writerId[3];
  static const OpenDDS::DCPS::RepoId readerId[3];

  AppConfig(int argc, ACE_TCHAR* argv[]);
  ~AppConfig();

  ACE_INET_Addr getHostAddress() const;
  ACE_TString getHost() const { return host; }
  u_short getPort() const { return port; }

  void to_cerr(const OpenDDS::DCPS::RepoId& remote, const OpenDDS::DCPS::RepoId& local, const std::string& txt) const;

private:
  static OpenDDS::DCPS::RepoId createID(long participantId, long key, CORBA::Octet kind);
  void cleanup();

  DDS::DomainParticipantFactory_var dpf;
  ACE_TString host;
  u_short port;
};
