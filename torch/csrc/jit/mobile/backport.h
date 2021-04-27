#pragma once
#include <torch/csrc/jit/mobile/module.h>

#include <istream>
#include <memory>

#include <caffe2/serialize/file_adapter.h>
#include <caffe2/serialize/inline_container.h>

namespace torch {
namespace jit {

// The family of methods below backport a model
TORCH_API bool _backport_for_mobile(std::istream& in, std::ostream& out);

TORCH_API bool _backport_for_mobile(
    std::istream& in,
    const std::string& output_filename);

TORCH_API bool _backport_for_mobile(
    const std::string& input_filename,
    std::ostream& out);

TORCH_API bool _backport_for_mobile(
    const std::string& input_filename,
    const std::string& output_filename);

TORCH_API bool _backport_for_mobile(
    std::shared_ptr<caffe2::serialize::ReadAdapterInterface> rai,
    std::shared_ptr<caffe2::serialize::PyTorchStreamWriter> writer);

TORCH_API bool _backport_to_version_for_mobile(
    std::istream& in,
    std::ostream& out,
    const int64_t to_version);

TORCH_API bool _backport_to_version_for_mobile(
    std::istream& in,
    const std::string& output_filename,
    const int64_t to_version);

TORCH_API bool _backport_to_version_for_mobile(
    const std::string& input_filename,
    std::ostream& out,
    const int64_t to_version);

TORCH_API bool _backport_to_version_for_mobile(
    const std::string& input_filename,
    const std::string& output_filename,
    const int64_t to_version);

TORCH_API bool _backport_to_version_for_mobile(
    std::shared_ptr<caffe2::serialize::ReadAdapterInterface> rai,
    std::unique_ptr<caffe2::serialize::PyTorchStreamWriter> writer,
    const int64_t to_version);

// The family of methods below to get version given bytecode model
TORCH_API int64_t _get_model_bytecode_version(std::istream& in);

TORCH_API int64_t _get_model_bytecode_version(const std::string& filename);

TORCH_API int64_t _get_model_bytecode_version(
    std::shared_ptr<caffe2::serialize::ReadAdapterInterface> rai);

} // namespace jit
} // namespace torch
