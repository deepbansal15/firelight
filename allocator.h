// Copyright 2021 Deep Bansal
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

namespace firelight {
namespace allocator {
// Block allocator
// Act as a wrapper on top of malloc/mmap and maintains a track just to notify
// in case of a leak.
// Desired capabilites: Recycle blocks

struct BlockAllocator {};

}  // namespace allocator
}  // namespace firelight