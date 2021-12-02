#pragma once

#include <Flash/Statistics/ExecutorStatistics.h>
#include <common/types.h>

#include <memory>

namespace DB
{
struct LimitStatistics : public ExecutorStatistics
{
    size_t limit;

    size_t inbound_rows = 0;
    size_t inbound_blocks = 0;
    size_t inbound_bytes = 0;

    LimitStatistics(const tipb::Executor * executor, Context & context);

    static bool hit(const String & executor_id);

    void collectRuntimeDetail() override;

protected:
    String extraToJson() const override;
};
} // namespace DB