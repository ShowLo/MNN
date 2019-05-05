//
//  SizeComputerTest.cpp
//  MNNTests
//
//  Created by MNN on 2019/01/16.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#include "MNNTestSuite.h"
#include "SizeComputer.hpp"

using namespace MNN;

class SUTSizeComputer : public SizeComputer {
    virtual bool onComputeSize(const MNN::Op* op, const std::vector<Tensor*>& inputs,
                               const std::vector<Tensor*>& outputs) const {
        return true;
    }
};

class SizeComputerTest : public MNNTestCase {
public:
    virtual ~SizeComputerTest() = default;
    virtual void run() {
        SizeComputerSuite suite;
        SUTSizeComputer* sut = new SUTSizeComputer;
        suite.insert(sut, OpType_ELU);
        assert(suite.search(OpType_ELU) == sut);
    }
};
MNNTestSuiteRegister(SizeComputerTest, "core/size_computer");