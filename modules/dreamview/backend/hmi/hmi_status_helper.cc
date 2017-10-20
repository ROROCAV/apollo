/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/dreamview/backend/hmi/hmi_status_helper.h"

namespace apollo {
namespace dreamview {
namespace {

void ReportHMIStatus(const HMIStatus& hmi_status) {
  // TODO(xiaoxq): Post HMIStatus on topic /apollo/hmi_status, then dreamview
  // backend will merge it into the global HMIStatus singleton and broadcast to
  // HMI clients through websocket.
}

}  // namespace

void HMIStatusHelper::ReportHardwareStatus(
    const std::vector<HardwareStatus> &hardware_status) {
  HMIStatus hmi_status;
  *hmi_status.mutable_hardware() = {hardware_status.begin(),
                                    hardware_status.end()};
  ReportHMIStatus(hmi_status);
}

void HMIStatusHelper::ReportModuleStatus(const ModuleStatus &module_status) {
  HMIStatus hmi_status;
  *hmi_status.add_modules() = module_status;
  ReportHMIStatus(hmi_status);
}

}  // namespace dreamview
}  // namespace apollo
