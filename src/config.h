#ifndef CONFIG_H_
#define CONFIG_H_

#include <algorithm>
#include <boost/property_tree/ini_parser.hpp>
#include <string>

struct CoreConfig {
  CoreConfig()
      : server("http://127.0.0.1:8080"), polling(true), polling_sec(10) {}

  std::string server;
  bool polling;
  unsigned long long polling_sec;
};

struct AuthConfig {
  AuthConfig()
      : server("http://127.0.0.1:9001"),
        client_id("client-id"),
        client_secret("client-secret") {}

  std::string server;
  std::string client_id;
  std::string client_secret;
};

struct DbusConfig {
  DbusConfig()
      : software_manager("org.genivi.SoftwareLoadingManager"),
        software_manager_path("/org/genivi/SoftwareLoadingManager"),
        path("/org/genivi/SotaClient"),
        interface("org.genivi.SotaClient"),
        timeout(0) {}

  std::string software_manager;
  std::string software_manager_path;
  std::string path;
  std::string interface;
  unsigned int timeout;
};

struct DeviceConfig {
  DeviceConfig()
      : uuid("123e4567-e89b-12d3-a456-426655440000"), packages_dir("/tmp/") {}

  std::string uuid;
  std::string packages_dir;
  // TODO Need to be implemented soon
  // PackageManager package_manager;
  // std::string certificates_path;
  // std::string p12_path;
  // std::string p12_password;
  // std::string system_info;
};

class Config {
 public:
  void updateFromToml(const std::string &filename);

  // config data structures
  CoreConfig core;
  AuthConfig auth;
  DeviceConfig device;
  DbusConfig dbus;
};
#endif  // CONFIG_H_
