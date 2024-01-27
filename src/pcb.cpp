//
// Created by yuant on 1/26/2024.
//

#include "../include/pcb.h"

PCB::PCB()
    : _state(Ready), _parent(0), _priority(Low), _children({}), _resources({}){
}

void PCB::setParent(PID pid) {
    _parent = pid;
}

void PCB::setPriority(Priority priority) {
    _priority = priority;
}

void PCB::block() {
    _state = Blocked;
}

Priority PCB::getPriority() {
    return _priority;
}

PID PCB::getParent() {
    return _parent;
}

void PCB::ready() {
    _state = Ready;
}

void PCB::addChild(PID pid) {
    _children.push_back(pid);
}

RC PCB::deleteChild(PID pid) {
    auto it = std::find(_children.begin(), _children.end(), pid);
    if (it != _children.end()) {
        _children.erase(it);
    }
    else {
        return -1; // return -1 for error code if the child does not exist
    }
    return 0;
}

void PCB::printChildren() {
    for (const auto& child: _children) {
        std::cout << child << " ";
    }
    std::cout << std::endl;
}





