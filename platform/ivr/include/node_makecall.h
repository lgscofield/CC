/*
 * Copyright 2002-2014 the original author or authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      CC/LICENSE
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _IVR_NODE_MAKECALL_H_
#define _IVR_NODE_MAKECALL_H_

#include "node_base.h"
#include "ims/ims_mgr.h"

// makecall
class NodeMakeCall : public NodeBase {
public:
    NodeMakeCall(const uint32_t id, const string& name,
                 const string& type, const string& desc, const key_map_t& keymap);

    virtual ~NodeMakeCall();

public:
    // run this node
    virtual NodeBase* run(base_script_t* param);

    virtual bool load_other();
private:
    // find exit, and return next node
    NodeBase* _find_exit_node(base_script_t* param, const char* exit);
private:
    // get information when enter node
    std::string enter(const map<string, variable_t>& vars) const;
private:
    std::string _agentdn;
    std::string _clientdn;
    std::string _showani;
    std::string _showdest;

    std::string _callmode;
    std::string _timeout;

    std::string _disable_event;
private:
    static const char* PARAM_TIMEOUT;
    static const char* PARAM_AGENTDN;
    static const char* PARAM_CLIENTDN;
    static const char* PARAM_SHOWANI;
    static const char* PARAM_SHOWDEST;
    static const char* PARAM_CALLMODE;
    static const char* PARAM_NOEVENT;
};

#endif
