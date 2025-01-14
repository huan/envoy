#include "source/common/quic/envoy_quic_proof_source_base.h"

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#include "quiche/quic/core/quic_data_writer.h"

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

#include "source/common/quic/envoy_quic_utils.h"

namespace Envoy {
namespace Quic {

void EnvoyQuicProofSourceBase::GetProof(const quic::QuicSocketAddress& /*server_address*/,
                                        const quic::QuicSocketAddress& /*client_address*/,
                                        const std::string& /*hostname*/,
                                        const std::string& /*server_config*/,
                                        quic::QuicTransportVersion /*transport_version*/,
                                        absl::string_view /*chlo_hash*/,
                                        std::unique_ptr<quic::ProofSource::Callback> /*callback*/) {
  // Only reachable in Google QUIC which is not supported by Envoy.
  NOT_REACHED_GCOVR_EXCL_LINE;
}

void EnvoyQuicProofSourceBase::ComputeTlsSignature(
    const quic::QuicSocketAddress& server_address, const quic::QuicSocketAddress& client_address,
    const std::string& hostname, uint16_t signature_algorithm, absl::string_view in,
    std::unique_ptr<quic::ProofSource::SignatureCallback> callback) {
  signPayload(server_address, client_address, hostname, signature_algorithm, in,
              std::move(callback));
}

} // namespace Quic
} // namespace Envoy
