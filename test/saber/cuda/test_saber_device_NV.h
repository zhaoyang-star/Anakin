/* Copyright (c) 2018 Anakin Authors, Inc. All Rights Reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0
   
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. 
*/

#ifndef SABER_TEST_SABER_DEVICE_NV_H
#define SABER_TEST_SABER_DEVICE_NV_H

#include "utils/unit_test/aktest.h"
#include "utils/logger/logger.h"
#include "core/device.h"

using namespace anakin::test;

class TestSaberDeviceNV : public Test {
public:
    TestSaberDeviceNV() {}
    ~TestSaberDeviceNV() {}

protected:
    virtual void setup() {}
    virtual void teardown() {}

};

#endif //SABER_TEST_SABER_DEVICE_NV_H
