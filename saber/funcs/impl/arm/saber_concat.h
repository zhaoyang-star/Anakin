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

#ifndef ANAKIN_SABER_FUNCS_IMPL_ARM_SABER_CONCAT_H
#define ANAKIN_SABER_FUNCS_IMPL_ARM_SABER_CONCAT_H

#include "saber/funcs/impl/impl_concat.h"
#include "saber/core/tensor.h"

#ifdef USE_ARM_PLACE

namespace anakin{

namespace saber{

template <DataType OpDtype,
        DataType inDtype,
        DataType outDtype,
        typename LayOutType_op,
        typename LayOutType_in,
        typename LayOutType_out>
class SaberConcat<ARM, OpDtype, inDtype, outDtype,\
    LayOutType_op, LayOutType_in, LayOutType_out> : \
    public ImplBase<
        Tensor<ARM, inDtype, LayOutType_in>,
        Tensor<ARM, outDtype, LayOutType_out>,
        Tensor<ARM, OpDtype, LayOutType_op>,
        ConcatParam<Tensor<ARM, OpDtype, LayOutType_op> > > {
public:
    typedef Tensor<ARM, inDtype, LayOutType_in> DataTensor_in;
    typedef Tensor<ARM, outDtype, LayOutType_out> DataTensor_out;
    typedef Tensor<ARM, OpDtype, LayOutType_op> OpTensor;
    typedef typename DataTensor_in::Dtype InDataType;
    typedef typename DataTensor_out::Dtype OutDataType;
    typedef typename OpTensor::Dtype OpDataType;

    SaberConcat() = default;
    ~SaberConcat() {}

    virtual SaberStatus init(const std::vector<DataTensor_in*>& inputs,
                      std::vector<DataTensor_out*>& outputs,
                      ConcatParam<OpTensor> &param, Context<ARM> &ctx){
        // get context
        this->_ctx = &ctx;
        return create(inputs, outputs, param, ctx);
    }

    virtual SaberStatus create(const std::vector<DataTensor_in*>& inputs,
                        std::vector<DataTensor_out*>& outputs,
                        ConcatParam<OpTensor> &param, Context<ARM> &ctx){

        _num_concats = inputs[0]->count_valid(0, param.axis);
        _concat_input_size = inputs[0]->count_valid(param.axis + 1, inputs[0]->dims());
        return SaberSuccess;
    }

    virtual SaberStatus dispatch(const std::vector<DataTensor_in*>& inputs,
                          std::vector<DataTensor_out*>& outputs,
                          ConcatParam<OpTensor> &param);

private:
    int _num_concats;
    int _concat_input_size;
};

} //namespace saber

} //namespace anakin

#endif //USE_ARM_PLACE

#endif //ANAKIN_SABER_FUNCS_IMPL_ARM_SABER_CONCAT_H
