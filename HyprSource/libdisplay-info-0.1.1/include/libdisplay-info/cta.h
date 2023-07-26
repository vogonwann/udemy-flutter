#ifndef DI_CTA_H
#define DI_CTA_H

/**
 * libdisplay-info's low-level API for Consumer Technology Association
 * standards.
 *
 * The library implements CTA-861-H, available at:
 * https://shop.cta.tech/collections/standards/products/a-dtv-profile-for-uncompressed-high-speed-digital-interfaces-cta-861-h
 */

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * CTA video format picture aspect ratio.
 */
enum di_cta_video_format_picture_aspect_ratio {
	DI_CTA_VIDEO_FORMAT_PICTURE_ASPECT_RATIO_4_3, /* 4:3 */
	DI_CTA_VIDEO_FORMAT_PICTURE_ASPECT_RATIO_16_9, /* 16:9 */
	DI_CTA_VIDEO_FORMAT_PICTURE_ASPECT_RATIO_64_27, /* 64:27 */
	DI_CTA_VIDEO_FORMAT_PICTURE_ASPECT_RATIO_256_135, /* 256:135 */
};

/**
 * CTA video format sync pulse polarity.
 */
enum di_cta_video_format_sync_polarity {
	DI_CTA_VIDEO_FORMAT_SYNC_NEGATIVE, /* Negative */
	DI_CTA_VIDEO_FORMAT_SYNC_POSITIVE, /* Positive */
};

/**
 * A CTA-861 video format, defined in section 4.
 */
struct di_cta_video_format {
	/* Video Identification Code (VIC) */
	uint8_t vic;
	/* Horizontal/vertical active pixels/lines */
	int32_t h_active, v_active;
	/* Horizontal/vertical front porch */
	int32_t h_front, v_front;
	/* Horizontal/vertical sync pulse */
	int32_t h_sync, v_sync;
	/* Horizontal/vertical back porch */
	int32_t h_back, v_back;
	/* Horizontal/vertical sync pulse polarity */
	enum di_cta_video_format_sync_polarity h_sync_polarity, v_sync_polarity;
	/* Pixel clock in Hz */
	int64_t pixel_clock_hz;
	/* Whether this timing is interlaced */
	bool interlaced;
	/* Picture aspect ratio */
	enum di_cta_video_format_picture_aspect_ratio picture_aspect_ratio;
};

/**
 * Get a CTA-861 video format from a VIC.
 *
 * Returns NULL if the VIC is unknown.
 */
const struct di_cta_video_format *
di_cta_video_format_from_vic(uint8_t vic);

/**
 * EDID CTA-861 extension block.
 */
struct di_edid_cta;

/**
 * Get the CTA extension revision (also referred to as "version" by the
 * specification).
 */
int
di_edid_cta_get_revision(const struct di_edid_cta *cta);

/**
 * Miscellaneous EDID CTA flags, defined in section 7.3.3.
 *
 * For CTA revision 1, all of the fields are zero.
 */
struct di_edid_cta_flags {
	/* Sink underscans IT Video Formats by default */
	bool it_underscan;
	/* Sink supports Basic Audio */
	bool basic_audio;
	/* Sink supports YCbCr 4:4:4 in addition to RGB */
	bool ycc444;
	/* Sink supports YCbCr 4:2:2 in addition to RGB */
	bool ycc422;
	/* Total number of native detailed timing descriptors */
	int native_dtds;
};

/**
 * Get miscellaneous CTA flags.
 */
const struct di_edid_cta_flags *
di_edid_cta_get_flags(const struct di_edid_cta *cta);

/**
 * CTA data block, defined in section 7.4.
 */
struct di_cta_data_block;

/**
 * Get CTA data blocks.
 *
 * The returned array is NULL-terminated.
 */
const struct di_cta_data_block *const *
di_edid_cta_get_data_blocks(const struct di_edid_cta *cta);

/**
 * CTA data block tag.
 *
 * Note, the enum values don't match the specification.
 */
enum di_cta_data_block_tag {
	/* Audio Data Block */
	DI_CTA_DATA_BLOCK_AUDIO = 1,
	/* Video Data Block */
	DI_CTA_DATA_BLOCK_VIDEO,
	/* Speaker Allocation Data Block */
	DI_CTA_DATA_BLOCK_SPEAKER_ALLOC,
	/* VESA Display Transfer Characteristic Data Block */
	DI_CTA_DATA_BLOCK_VESA_DISPLAY_TRANSFER_CHARACTERISTIC,
	/* Video Format Data Block */
	DI_CTA_DATA_BLOCK_VIDEO_FORMAT,

	/* Video Capability Data Block */
	DI_CTA_DATA_BLOCK_VIDEO_CAP,
	/* VESA Display Device Data Block */
	DI_CTA_DATA_BLOCK_VESA_DISPLAY_DEVICE,
	/* Colorimetry Data Block */
	DI_CTA_DATA_BLOCK_COLORIMETRY,
	/* HDR Static Metadata Data Block */
	DI_CTA_DATA_BLOCK_HDR_STATIC_METADATA,
	/* HDR Dynamic Metadata Data Block */
	DI_CTA_DATA_BLOCK_HDR_DYNAMIC_METADATA,
	/* Native Video Resolution Data Block */
	DI_CTA_DATA_BLOCK_NATIVE_VIDEO_RESOLUTION,
	/* Video Format Preference Data Block */
	DI_CTA_DATA_BLOCK_VIDEO_FORMAT_PREF,
	/* YCbCr 4:2:0 Video Data Block */
	DI_CTA_DATA_BLOCK_YCBCR420,
	/* YCbCr 4:2:0 Capability Map Data Block */
	DI_CTA_DATA_BLOCK_YCBCR420_CAP_MAP,
	/* HDMI Audio Data Block */
	DI_CTA_DATA_BLOCK_HDMI_AUDIO,
	/* Room Configuration Data Block */
	DI_CTA_DATA_BLOCK_ROOM_CONFIG,
	/* Speaker Location Data Block */
	DI_CTA_DATA_BLOCK_SPEAKER_LOCATION,
	/* InfoFrame Data Block */
	DI_CTA_DATA_BLOCK_INFOFRAME,
	/* DisplayID Type VII Video Timing Data Block */
	DI_CTA_DATA_BLOCK_DISPLAYID_VIDEO_TIMING_VII,
	/* DisplayID Type VIII Video Timing Data Block */
	DI_CTA_DATA_BLOCK_DISPLAYID_VIDEO_TIMING_VIII,
	/* DisplayID Type X Video Timing Data Block */
	DI_CTA_DATA_BLOCK_DISPLAYID_VIDEO_TIMING_X,
	/* HDMI Forum EDID Extension Override Data Block */
	DI_CTA_DATA_BLOCK_HDMI_EDID_EXT_OVERRIDE,
	/* HDMI Forum Sink Capability Data Block */
	DI_CTA_DATA_BLOCK_HDMI_SINK_CAP,
};

/**
 * Get the tag of the CTA data block.
 */
enum di_cta_data_block_tag
di_cta_data_block_get_tag(const struct di_cta_data_block *block);

/**
 * Audio formats, defined in tables 37 and 39.
 *
 * Note, the enum values don't match the specification.
 */
enum di_cta_audio_format {
	/* L-PCM */
	DI_CTA_AUDIO_FORMAT_LPCM = 1,
	/* AC-3 */
	DI_CTA_AUDIO_FORMAT_AC3,
	/* MPEG-1 (layers 1 & 2) */
	DI_CTA_AUDIO_FORMAT_MPEG1,
	/* MP3 */
	DI_CTA_AUDIO_FORMAT_MP3,
	/* MPEG-2 */
	DI_CTA_AUDIO_FORMAT_MPEG2,
	/* AAC LC */
	DI_CTA_AUDIO_FORMAT_AAC_LC,
	/* DTS */
	DI_CTA_AUDIO_FORMAT_DTS,
	/* ATRAC */
	DI_CTA_AUDIO_FORMAT_ATRAC,
	/* One Bit Audio */
	DI_CTA_AUDIO_FORMAT_ONE_BIT_AUDIO,
	/* Enhanced AC-3 */
	DI_CTA_AUDIO_FORMAT_ENHANCED_AC3,
	/* DTS-HD and DTS-UHD */
	DI_CTA_AUDIO_FORMAT_DTS_HD,
	/* MAT */
	DI_CTA_AUDIO_FORMAT_MAT,
	/* DST */
	DI_CTA_AUDIO_FORMAT_DST,
	/* WMA Pro */
	DI_CTA_AUDIO_FORMAT_WMA_PRO,

	/* MPEG-4 HE AAC */
	DI_CTA_AUDIO_FORMAT_MPEG4_HE_AAC,
	/* MPEG-4 HE AAC v2 */
	DI_CTA_AUDIO_FORMAT_MPEG4_HE_AAC_V2,
	/* MPEG-4 AAC LC */
	DI_CTA_AUDIO_FORMAT_MPEG4_AAC_LC,
	/* DRA */
	DI_CTA_AUDIO_FORMAT_DRA,
	/* MPEG-4 HE AAC + MPEG Surround */
	DI_CTA_AUDIO_FORMAT_MPEG4_HE_AAC_MPEG_SURROUND,
	/* MPEG-4 AAC LC + MPEG Surround */
	DI_CTA_AUDIO_FORMAT_MPEG4_AAC_LC_MPEG_SURROUND,
	/* MPEG-H 3D Audio */
	DI_CTA_AUDIO_FORMAT_MPEGH_3D,
	/* AC-4 */
	DI_CTA_AUDIO_FORMAT_AC4,
	/* L-PCM 3D Audio */
	DI_CTA_AUDIO_FORMAT_LPCM_3D,
};

struct di_cta_sad_sample_rates {
	bool has_192_khz; /* 192 kHz */
	bool has_176_4_khz; /* 176.4 kHz */
	bool has_96_khz; /* 96 kHz */
	bool has_88_2_khz; /* 88.2 kHz */
	bool has_48_khz; /* 48 kHz */
	bool has_44_1_khz; /* 44.1 kHz */
	bool has_32_khz; /* 32 kHz */
};

enum di_cta_sad_mpegh_3d_level {
	DI_CTA_SAD_MPEGH_3D_LEVEL_UNSPECIFIED = 0,
	DI_CTA_SAD_MPEGH_3D_LEVEL_1 = 1,
	DI_CTA_SAD_MPEGH_3D_LEVEL_2 = 2,
	DI_CTA_SAD_MPEGH_3D_LEVEL_3 = 3,
	DI_CTA_SAD_MPEGH_3D_LEVEL_4 = 4,
	DI_CTA_SAD_MPEGH_3D_LEVEL_5 = 5,
};

struct di_cta_sad_mpegh_3d {
	/* Maximum supported MPEG-H 3D level, zero if unspecified */
	enum di_cta_sad_mpegh_3d_level level;
	/* True if MPEG-H 3D Audio Low Complexity Profile is supported */
	bool low_complexity_profile;
	/* True if MPEG-H 3D Audio Baseline Profile is supported */
	bool baseline_profile;
};

struct di_cta_sad_mpeg_aac {
	/* True if AAC audio frame lengths of 960 samples is supported */
	bool has_frame_length_960;
	/* True if AAC audio frame lengths of 1024 samples is supported */
	bool has_frame_length_1024;
};

enum di_cta_sad_mpeg_surround_signaling {
	/* Only implicitly signaled MPEG Surround data supported */
	DI_CTA_SAD_MPEG_SURROUND_SIGNALING_IMPLICIT = 0,
	/* Implicitly and explicitly signaled MPEG Surround data supported */
	DI_CTA_SAD_MPEG_SURROUND_SIGNALING_IMPLICIT_AND_EXPLICIT = 1,
};

struct di_cta_sad_mpeg_surround {
	/* MPEG Surround signaling */
	enum di_cta_sad_mpeg_surround_signaling signaling;
};

struct di_cta_sad_mpeg_aac_le {
	/* True if Rec. ITU-R BS.2051 System H 22.2 multichannel sound is supported */
	bool supports_multichannel_sound;
};

struct di_cta_sad_lpcm {
	bool has_sample_size_24_bits; /* 24 bits */
	bool has_sample_size_20_bits; /* 20 bits */
	bool has_sample_size_16_bits; /* 16 bits */
};

struct di_cta_sad_enhanced_ac3 {
	bool supports_joint_object_coding;
	bool supports_joint_object_coding_ACMOD28;
};

struct di_cta_sad_mat {
	bool supports_object_audio_and_channel_based;
	bool requires_hash_calculation;
};

struct di_cta_sad_wma_pro {
	int profile;
};

/**
 * A CTA short audio descriptor (SAD), defined in section 7.5.2.
 */
struct di_cta_sad {
	/* Format */
	enum di_cta_audio_format format;
	/* Maximum number of channels, zero if unset */
	int32_t max_channels;
	/* Supported sample rates */
	const struct di_cta_sad_sample_rates *supported_sample_rates;
	/* Maximum bitrate (kb/s), zero if unset */
	int32_t max_bitrate_kbs;
	/* Additional metadata for LPCM, NULL unless format is
	 * DI_CTA_AUDIO_FORMAT_LPCM or DI_CTA_AUDIO_FORMAT_LPCM_3D */
	const struct di_cta_sad_lpcm *lpcm;
	/* Additional metadata for MPEG-H 3D Audio, NULL unless format is
	 * DI_CTA_AUDIO_FORMAT_MPEGH_3D */
	const struct di_cta_sad_mpegh_3d *mpegh_3d;
	/* Additional metadata for MPEG4 AAC, NULL unless format is
	 * DI_CTA_AUDIO_FORMAT_MPEG4_HE_AAC or
	 * DI_CTA_AUDIO_FORMAT_MPEG4_HE_AAC_V2 or
	 * DI_CTA_AUDIO_FORMAT_MPEG4_AAC_LC or
	 * DI_CTA_AUDIO_FORMAT_MPEG4_HE_AAC_MPEG_SURROUND or
	 * DI_CTA_AUDIO_FORMAT_MPEG4_AAC_LC_MPEG_SURROUND */
	const struct di_cta_sad_mpeg_aac *mpeg_aac;
	/* Additional metadata for MPEG4 Surround, NULL unless format is
	 * DI_CTA_AUDIO_FORMAT_MPEG4_HE_AAC_MPEG_SURROUND or
	 * DI_CTA_AUDIO_FORMAT_MPEG4_AAC_LC_MPEG_SURROUND */
	const struct di_cta_sad_mpeg_surround *mpeg_surround;
	/* Additional metadata for MPEG4 AAC LC, NULL unless format is
	 * DI_CTA_AUDIO_FORMAT_MPEG4_AAC_LC */
	const struct di_cta_sad_mpeg_aac_le *mpeg_aac_le;
	/* Additional metadata for Enhanced AC-3, NULL unless format is
	 * DI_CTA_AUDIO_FORMAT_ENHANCED_AC3 */
	const struct di_cta_sad_enhanced_ac3 *enhanced_ac3;
	/* Additional metadata for Dolby MAT, NULL unless format is
	 * DI_CTA_AUDIO_FORMAT_MAT */
	const struct di_cta_sad_mat *mat;
	/* Additional metadata for WMA Pro, NULL unless format is
	 * DI_CTA_AUDIO_FORMAT_WMA_PRO */
	const struct di_cta_sad_wma_pro *wma_pro;
};

/**
 * Get an array of short audio descriptors from a CTA data block.
 *
 * Returns NULL if the data block tag is not DI_CTA_DATA_BLOCK_AUDIO.
 *
 * The returned array is NULL-terminated.
 */
const struct di_cta_sad *const *
di_cta_data_block_get_sads(const struct di_cta_data_block *data_block);

/**
 * Speaker allocation data block (SADB), defined in section 7.5.3.
 *
 * This block indicates which speakers are present. See figure 6 for the meaning
 * of the fields.
 */
struct di_cta_speaker_alloc_block {
	bool flw_frw; /* FLw/FRw - Front Left/Right Wide */
	bool flc_frc; /* FLc/FRc - Front Left/Right of Center */
	bool bc; /* BC - Back Center */
	bool bl_br; /* BL/BR - Back Left/Right */
	bool fc; /* FC - Front Center */
	bool lfe1; /* LFE1 - Low Frequency Effects 1 */
	bool fl_fr; /* FL/FR - Front Left/Right */
	bool tpsil_tpsir; /* TpSiL/TpSiR - Top Side Left/Right */
	bool sil_sir; /* SiL/SiR - Side Left/Right */
	bool tpbc; /* TpBC - Top Back Center */
	bool lfe2; /* LFE2 - Low Frequency Effects 2 */
	bool ls_rs; /* LS/RS - Left/Right Surround*/
	bool tpfc; /* TpFC - Top Front Center */
	bool tpc; /* TpC - Top Center*/
	bool tpfl_tpfr; /* TpFL/TpFR - Top Front Left/Right */
	bool btfl_btfr; /* BtFL/BtFR - Bottom Front Left/Right */
	bool btfc; /* BtFC - Bottom Front Center */
	bool tpbl_tpbr; /* TpBL/TpBR - Top Back Left/Right */
};

/**
 * Get the speaker allocation from a CTA data block.
 *
 * Returns NULL if the data block tag is not DI_CTA_DATA_BLOCK_SPEAKER_ALLOC.
 */
const struct di_cta_speaker_alloc_block *
di_cta_data_block_get_speaker_alloc(const struct di_cta_data_block *block);

/**
 * Over- and underscan capability.
 */
enum di_cta_video_cap_over_underscan {
	/* No data */
	DI_CTA_VIDEO_CAP_UNKNOWN_OVER_UNDERSCAN = 0x00,
	/* Always overscanned */
	DI_CTA_VIDEO_CAP_ALWAYS_OVERSCAN = 0x01,
	/* Always underscanned */
	DI_CTA_VIDEO_CAP_ALWAYS_UNDERSCAN = 0x02,
	/* Supports both over- and underscan */
	DI_CTA_VIDEO_CAP_BOTH_OVER_UNDERSCAN = 0x03,
};

/**
 * Video capability data block (VCDB), defined in section 7.5.6.
 */
struct di_cta_video_cap_block {
	/* If set to true, YCC quantization range is selectable (via AVI YQ). */
	bool selectable_ycc_quantization_range;
	/* If set to true, RGB quantization range is selectable (via AVI Q). */
	bool selectable_rgb_quantization_range;
	/* Overscan/underscan behavior for PT video formats (if set to unknown,
	 * use the IT/CE behavior) */
	enum di_cta_video_cap_over_underscan pt_over_underscan;
	/* Overscan/underscan behavior for IT video formats */
	enum di_cta_video_cap_over_underscan it_over_underscan;
	/* Overscan/underscan behavior for CE video formats */
	enum di_cta_video_cap_over_underscan ce_over_underscan;
};

/**
 * Get the video capabilities from a CTA data block.
 *
 * Returns NULL if the data block tag is not DI_CTA_DATA_BLOCK_VIDEO_CAP.
 */
const struct di_cta_video_cap_block *
di_cta_data_block_get_video_cap(const struct di_cta_data_block *block);

/**
 * Interface types, defined in VESA DDDB section 2.3.1 and 2.3.2.
 *
 * Note, the enum values don't match the specification.
 */
enum di_cta_vesa_dddb_interface_type {
	DI_CTA_VESA_DDDB_INTERFACE_VGA, /* 15HD/VGA */
	DI_CTA_VESA_DDDB_INTERFACE_NAVI_V, /* VESA NAVI-V */
	DI_CTA_VESA_DDDB_INTERFACE_NAVI_D, /* VESA NAVI-D */
	DI_CTA_VESA_DDDB_INTERFACE_LVDS, /* LVDS */
	DI_CTA_VESA_DDDB_INTERFACE_RSDS, /* RSDS */
	DI_CTA_VESA_DDDB_INTERFACE_DVI_D, /* DVI-D */
	DI_CTA_VESA_DDDB_INTERFACE_DVI_I_ANALOG, /* DVI-I analog */
	DI_CTA_VESA_DDDB_INTERFACE_DVI_I_DIGITAL, /* DVI-I digital */
	DI_CTA_VESA_DDDB_INTERFACE_HDMI_A, /* HDMI-A */
	DI_CTA_VESA_DDDB_INTERFACE_HDMI_B, /* HDMI-B */
	DI_CTA_VESA_DDDB_INTERFACE_MDDI, /* MDDI */
	DI_CTA_VESA_DDDB_INTERFACE_DISPLAYPORT, /* DisplayPort */
	DI_CTA_VESA_DDDB_INTERFACE_IEEE_1394, /* IEEE-1394 */
	DI_CTA_VESA_DDDB_INTERFACE_M1_ANALOG, /* M1 analog */
	DI_CTA_VESA_DDDB_INTERFACE_M1_DIGITAL, /* M1 digital */
};

enum di_cta_vesa_dddb_content_protection {
	DI_CTA_VESA_DDDB_CONTENT_PROTECTION_NONE = 0x00, /* None */
	DI_CTA_VESA_DDDB_CONTENT_PROTECTION_HDCP = 0x01, /* HDCP */
	DI_CTA_VESA_DDDB_CONTENT_PROTECTION_DTCP = 0x02, /* DTCP */
	DI_CTA_VESA_DDDB_CONTENT_PROTECTION_DPCP = 0x03, /* DPCP */
};

enum di_cta_vesa_dddb_default_orientation {
	DI_CTA_VESA_DDDB_DEFAULT_ORIENTATION_LANDSCAPE = 0, /* Landscape */
	DI_CTA_VESA_DDDB_DEFAULT_ORIENTATION_PORTAIT = 1, /* Portrait */
	DI_CTA_VESA_DDDB_DEFAULT_ORIENTATION_UNFIXED = 2, /* Not fixed, may be rotated by the user */
	DI_CTA_VESA_DDDB_DEFAULT_ORIENTATION_UNDEFINED = 3, /* Undefined */
};

enum di_cta_vesa_dddb_rotation_cap {
	DI_CTA_VESA_DDDB_ROTATION_CAP_NONE = 0, /* No rotation capability */
	DI_CTA_VESA_DDDB_ROTATION_CAP_90DEG_CLOCKWISE = 1, /* 90 degrees clockwise */
	DI_CTA_VESA_DDDB_ROTATION_CAP_90DEG_COUNTERCLOCKWISE = 2, /* 90 degrees counterclockwise */
	DI_CTA_VESA_DDDB_ROTATION_CAP_90DEG_EITHER = 3, /* 90 degrees in either direction */
};

enum di_cta_vesa_dddb_zero_pixel_location {
	DI_CTA_VESA_DDDB_ZERO_PIXEL_UPPER_LEFT = 0, /* Upper left corner */
	DI_CTA_VESA_DDDB_ZERO_PIXEL_UPPER_RIGHT = 1, /* Upper right corner */
	DI_CTA_VESA_DDDB_ZERO_PIXEL_LOWER_LEFT = 2, /* Lower left corner */
	DI_CTA_VESA_DDDB_ZERO_PIXEL_LOWER_RIGHT = 3, /* Lower right corner */
};

enum di_cta_vesa_dddb_scan_direction {
	/* Undefined */
	DI_CTA_VESA_DDDB_SCAN_DIRECTION_UNDEFINED = 0,
	/* Fast (line) scan is along the long axis, slow (frame or field) scan
	 * is along the short axis */
	DI_CTA_VESA_DDDB_SCAN_DIRECTION_FAST_LONG_SLOW_SHORT = 1,
	/* Fast (line) scan is along the short axis, slow (frame or field) scan
	 * is along the long axis */
	DI_CTA_VESA_DDDB_SCAN_DIRECTION_FAST_SHORT_SLOW_LONG = 2,
};

/**
 * Subpixel layout, defined in VESA DDDB section 2.9.
 *
 * For layouts with more than 3 subpixels, the color coordinates of the
 * additional subpixels are defined in the additional primary chromaticities.
 */
enum di_cta_vesa_dddb_subpixel_layout {
	/* Undefined */
	DI_CTA_VESA_DDDB_SUBPIXEL_UNDEFINED = 0x00,
	/* Red, green, blue vertical stripes */
	DI_CTA_VESA_DDDB_SUBPIXEL_RGB_VERT = 0x01,
	/* Red, green, blue horizontal stripes */
	DI_CTA_VESA_DDDB_SUBPIXEL_RGB_HORIZ = 0x02,
	/* Vertical stripes with the primary ordering given by the order of the
	 * chromaticity information in the base EDID */
	DI_CTA_VESA_DDDB_SUBPIXEL_EDID_CHROM_VERT = 0x03,
	/* Horizontal stripes with the primary ordering given by the order of
	 * the chromaticity information in the base EDID */
	DI_CTA_VESA_DDDB_SUBPIXEL_EDID_CHROM_HORIZ = 0x04,
	/* Quad subpixels:
	 * R G
	 * G B
	 */
	DI_CTA_VESA_DDDB_SUBPIXEL_QUAD_RGGB = 0x05,
	/* Quad subpixels:
	 * G B
	 * R G
	 */
	DI_CTA_VESA_DDDB_SUBPIXEL_QUAD_GBRG = 0x06,
	/* Delta (triad) RGB subpixels */
	DI_CTA_VESA_DDDB_SUBPIXEL_DELTA_RGB = 0x07,
	/* Mosaic */
	DI_CTA_VESA_DDDB_SUBPIXEL_MOSAIC = 0x08,
	/* Quad subpixels: one each of red, green, blue, and one additional
	 * color (including white) in any order */
	DI_CTA_VESA_DDDB_SUBPIXEL_QUAD_ANY = 0x09,
	/* Five subpixels, including RGB subpixels aligned as in the case of
	 * DI_CTA_VESA_DDDB_SUBPIXEL_RGB_VERT, with two additional subpixels
	 * located above or below this group */
	DI_CTA_VESA_DDDB_SUBPIXEL_FIVE = 0x0A,
	/* Six subpixels, including RGB subpixels aligned as in the case of
	 * DI_CTA_VESA_DDDB_SUBPIXEL_RGB_VERT, with three additional subpixels
	 * located above or below this group */
	DI_CTA_VESA_DDDB_SUBPIXEL_SIX = 0x0B,
	/* Clairvoyante, Inc. PenTile Matrix™ layout */
	DI_CTA_VESA_DDDB_SUBPIXEL_CLAIRVOYANTE_PENTILE = 0x0C,
};

enum di_cta_vesa_dddb_dithering_type {
	DI_CTA_VESA_DDDB_DITHERING_NONE = 0, /* None */
	DI_CTA_VESA_DDDB_DITHERING_SPACIAL = 1, /* Spacial */
	DI_CTA_VESA_DDDB_DITHERING_TEMPORAL = 2, /* Temporal */
	DI_CTA_VESA_DDDB_DITHERING_SPATIAL_AND_TEMPORAL = 3, /* Spacial and temporal */
};

struct di_cta_vesa_dddb_additional_primary_chromaticity {
	float x, y;
};

enum di_cta_vesa_dddb_frame_rate_conversion {
	/* No dedicated rate conversion hardware is provided */
	DI_CTA_VESA_DDDB_FRAME_RATE_CONVERSION_NONE = 0,
	/* Frame rate conversion is supported, tearing or other artifacts may
	 * be visible */
	DI_CTA_VESA_DDDB_FRAME_RATE_CONVERSION_SINGLE_BUFFERING = 1,
	/* Frame rate conversion is supported, input frames may be duplicated or
	 * dropped */
	DI_CTA_VESA_DDDB_FRAME_RATE_CONVERSION_DOUBLE_BUFFERING = 2,
	/* Frame rate conversion is supported via a more advanced technique
	 * (e.g. inter-frame interpolation) */
	DI_CTA_VESA_DDDB_FRAME_RATE_CONVERSION_ADVANCED = 3,
};

enum di_cta_vesa_dddb_resp_time_transition {
	DI_CTA_VESA_DDDB_RESP_TIME_BLACK_TO_WHITE = 0, /* Black to white */
	DI_CTA_VESA_DDDB_RESP_TIME_WHITE_TO_BLACK = 1, /* White to black */
};

/**
 * VESA Display Device Data Block (DDDB), defined in VESA Display Device Data
 * Block (DDDB) Standard version 1.
 */
struct di_cta_vesa_dddb {
	/* Interface type */
	enum di_cta_vesa_dddb_interface_type interface_type;
	/* Number of lanes/channels, zero if N/A */
	int32_t num_channels;
	/* Interface standard version and release number */
	int32_t interface_version, interface_release;
	/* Content protection support */
	enum di_cta_vesa_dddb_content_protection content_protection;
	/* Minimum and maximum clock frequency (in mega-hertz), zero if unset
	 * (ie. maximum and minimum as permitted under the appropriate interface
	 * specification or standard) */
	int32_t min_clock_freq_mhz, max_clock_freq_mhz;
	/* Device native pixel format, zero if unset */
	int32_t native_horiz_pixels, native_vert_pixels;
	/* Aspect ratio taken as long axis divided by short axis */
	float aspect_ratio;
	/* Default orientation */
	enum di_cta_vesa_dddb_default_orientation default_orientation;
	/* Rotation capability */
	enum di_cta_vesa_dddb_rotation_cap rotation_cap;
	/* Zero pixel location */
	enum di_cta_vesa_dddb_zero_pixel_location zero_pixel_location;
	/* Scan direction */
	enum di_cta_vesa_dddb_scan_direction scan_direction;
	/* Subpixel layout */
	enum di_cta_vesa_dddb_subpixel_layout subpixel_layout;
	/* Horizontal and vertical dot/pixel pitch (in millimeters) */
	float horiz_pitch_mm, vert_pitch_mm;
	/* Dithering type */
	enum di_cta_vesa_dddb_dithering_type dithering_type;
	/* Direct drive: no scaling, de-interlacing, frame-rate conversion, etc.
	 * between this interface and the panel or other display device */
	bool direct_drive;
	/* Overdrive not recommended: the source should not apply "overdrive" to
	 * the video signal */
	bool overdrive_not_recommended;
	/* Display can deinterlaced video input */
	bool deinterlacing;
	/* Video interface supports audio */
	bool audio_support;
	/* Audio inputs are provided separately from the video interface */
	bool separate_audio_inputs;
	/* Audio information received via the video interface will automatically
	 * override any other audio input channels provided */
	bool audio_input_override;
	/* True if audio delay information is provided */
	bool audio_delay_provided;
	/* Audio delay (in milliseconds, may be negative), with the maximum
	 * absolute value of 254 ms */
	int32_t audio_delay_ms;
	/* Frame rate/mode conversion */
	enum di_cta_vesa_dddb_frame_rate_conversion frame_rate_conversion;
	/* Frame rate range (in Hz), with the maximum value of 63 Hz */
	int32_t frame_rate_range_hz;
	/* Native/nominal rate (in Hz) */
	int32_t frame_rate_native_hz;
	/* Color bit depth for the interface and display device */
	int32_t bit_depth_interface, bit_depth_display;
	/* Number of additional primary color chromaticities */
	size_t additional_primary_chromaticities_len;
	/* Additional primary color chromaticities given as 1931 CIE xy color
	 * space coordinates (also defines the color of subpixels for some
	 * subpixel layouts) */
	struct di_cta_vesa_dddb_additional_primary_chromaticity additional_primary_chromaticities[3];
	/* Response time transition */
	enum di_cta_vesa_dddb_resp_time_transition resp_time_transition;
	/* Response time (in milliseconds), with the maximum value of 127 ms */
	int32_t resp_time_ms;
	/* Overscan horizontal and vertical percentage */
	int32_t overscan_horiz_pct, overscan_vert_pct;
};

/**
 * Get the VESA Display Device Data Block (DDDB) from a CTA data block.
 *
 * Returns NULL if the data block tag is not
 * DI_CTA_DATA_BLOCK_VESA_DISPLAY_DEVICE.
 */
const struct di_cta_vesa_dddb *
di_cta_data_block_get_vesa_dddb(const struct di_cta_data_block *block);

/**
 * CTA colorimetry data block, defined in section 7.5.5.
 */
struct di_cta_colorimetry_block {
	/* Standard Definition Colorimetry based on IEC 61966-2-4 */
	bool xvycc_601;
	/* High Definition Colorimetry based on IEC 61966-2-4 */
	bool xvycc_709;
	/* Colorimetry based on IEC 61966-2-1/Amendment 1 */
	bool sycc_601;
	/* Colorimetry based on IEC 61966-2-5, Annex A */
	bool opycc_601;
	/* Colorimetry based on IEC 61966-2-5 */
	bool oprgb;
	/* Colorimetry based on Rec. ITU-R BT.2020 Y'cC'bcC'rc */
	bool bt2020_cycc;
	/* Colorimetry based on Rec. ITU-R BT.2020 Y'C'bC'r */
	bool bt2020_ycc;
	/* Colorimetry based on Rec. ITU-R BT.2020 R'G'B' */
	bool bt2020_rgb;
	/* Colorimetry based on SMPTE ST 2113 R'G'B' */
	bool st2113_rgb;
	/* Colorimetry based on Rec. ITU-R BT.2100 ICtCp */
	bool ictcp;
};

/**
 * Get the colorimetry data from a CTA data block.
 *
 * Returns NULL if the data block tag is not DI_CTA_DATA_BLOCK_COLORIMETRY.
 */
const struct di_cta_colorimetry_block *
di_cta_data_block_get_colorimetry(const struct di_cta_data_block *block);

/**
 * Supported Electro-Optical Transfer Functions for a CTA HDR static metadata
 * block.
 */
struct di_cta_hdr_static_metadata_block_eotfs {
	/* Traditional gamma - SDR luminance range */
	bool traditional_sdr;
	/* Traditional gamma - HDR luminance range */
	bool traditional_hdr;
	/* Perceptual Quantization (PQ) based on SMPTE ST 2084 */
	bool pq;
	/* Hybrid Log-Gamma (HLG) based on Rec. ITU-R BT.2100 */
	bool hlg;
};

/**
 * Supported static metadata descriptors for a CTA HDR static metadata block.
 */
struct di_cta_hdr_static_metadata_block_descriptors {
	/* Static Metadata Type 1 */
	bool type1;
};

/**
 * CTA HDR static metadata block, defined in section 7.5.13.
 */
struct di_cta_hdr_static_metadata_block {
	/* Desired content max luminance (cd/m²), zero if unset */
	float desired_content_max_luminance;
	/* Desired content max frame-average luminance (cd/m²), zero if unset */
	float desired_content_max_frame_avg_luminance;
	/* Desired content min luminance (cd/m²), zero if unset */
	float desired_content_min_luminance;
	/* Supported EOFTs */
	const struct di_cta_hdr_static_metadata_block_eotfs *eotfs;
	/* Supported descriptors */
	const struct di_cta_hdr_static_metadata_block_descriptors *descriptors;
};

/**
 * Get the HDR static metadata from a CTA data block.
 *
 * Returns NULL if the data block tag is not
 * DI_CTA_DATA_BLOCK_HDR_STATIC_METADATA.
 */
const struct di_cta_hdr_static_metadata_block *
di_cta_data_block_get_hdr_static_metadata(const struct di_cta_data_block *block);

/* Additional HDR Dynamic Metadata Type 1 information */
struct di_cta_hdr_dynamic_metadata_block_type1 {
	uint8_t type_1_hdr_metadata_version;
};

/* Additional HDR Dynamic Metadata Type 2 (ETSI TS 103 433-1) information.
 * Defined in ETSI TS 103 433-1 Annex G.2 HDR Dynamic Metadata Data Block. */
struct di_cta_hdr_dynamic_metadata_block_type2 {
	uint8_t ts_103_433_spec_version;
	bool ts_103_433_1_capable;
	bool ts_103_433_2_capable;
	bool ts_103_433_3_capable;
};

/* Additional HDR Dynamic Metadata Type 3 information */
struct di_cta_hdr_dynamic_metadata_block_type3;

/* Additional HDR Dynamic Metadata Type 4 information */
struct di_cta_hdr_dynamic_metadata_block_type4 {
	uint8_t type_4_hdr_metadata_version;
};

/* Additional HDR Dynamic Metadata Type 256 information */
struct di_cta_hdr_dynamic_metadata_block_type256 {
	uint8_t graphics_overlay_flag_version;
};

/**
 * CTA HDR dynamic metadata block, defined in section 7.5.14.
 */
struct di_cta_hdr_dynamic_metadata_block {
	/* non-NULL if Dynamic Metadata Type 1 is supported. */
	const struct di_cta_hdr_dynamic_metadata_block_type1 *type1;
	/* non-NULL if Dynamic Metadata Type 2 is supported. */
	const struct di_cta_hdr_dynamic_metadata_block_type2 *type2;
	/* non-NULL if Dynamic Metadata Type 3 is supported. */
	const struct di_cta_hdr_dynamic_metadata_block_type3 *type3;
	/* non-NULL if Dynamic Metadata Type 4 is supported. */
	const struct di_cta_hdr_dynamic_metadata_block_type4 *type4;
	/* non-NULL if Dynamic Metadata Type 256 (0x0100) is supported. */
	const struct di_cta_hdr_dynamic_metadata_block_type256 *type256;
};

/**
 * Get the HDR dynamic metadata from a CTA data block.
 *
 * Returns NULL if the data block tag is not
 * DI_CTA_DATA_BLOCK_HDR_DYNAMIC_METADATA.
 */
const struct di_cta_hdr_dynamic_metadata_block *
di_cta_data_block_get_hdr_dynamic_metadata(const struct di_cta_data_block *block);

/**
 * A Short Video Descriptor (SVD).
 */
struct di_cta_svd {
	/* Video Identification Code (VIC) */
	uint8_t vic;
	/* Whether this is a native video format */
	bool native;
};

/**
 * Get an array of short video descriptors from a CTA data block.
 *
 * Returns NULL if the data block tag is not DI_CTA_DATA_BLOCK_VIDEO.
 *
 * The returned array is NULL-terminated.
 */
const struct di_cta_svd *const *
di_cta_data_block_get_svds(const struct di_cta_data_block *block);

/**
 * Get an array of short video descriptors which only allow YCbCr 4:2:0 sampling
 * mode from a CTA data block.
 *
 * Returns NULL if the data block tag is not DI_CTA_DATA_BLOCK_YCBCR420.
 *
 * The returned array is NULL-terminated.
 */
const struct di_cta_svd *const *
di_cta_data_block_get_ycbcr420_svds(const struct di_cta_data_block *block);

enum di_cta_vesa_transfer_characteristics_usage {
	/* White transfer characteristic */
	DI_CTA_VESA_TRANSFER_CHARACTERISTIC_USAGE_WHITE = 0,
	/* Red transfer characteristic */
	DI_CTA_VESA_TRANSFER_CHARACTERISTIC_USAGE_RED = 1,
	/* Green transfer characteristic */
	DI_CTA_VESA_TRANSFER_CHARACTERISTIC_USAGE_GREEN = 2,
	/* Blue transfer characteristic */
	DI_CTA_VESA_TRANSFER_CHARACTERISTIC_USAGE_BLUE = 3,
};

/**
 * VESA Display Transfer Characteristic Data Block, defined in VESA Display
 * Transfer Characteristics Data Block Standard Version 1.0
 *
 * Contains 8, 16 or 32 evenly distributed points on the input axis describing
 * the normalized relative luminance at that input. The first value includes the
 * relative black level luminance.
 */
struct di_cta_vesa_transfer_characteristics {
	enum di_cta_vesa_transfer_characteristics_usage usage;
	uint8_t points_len;
	float points[32];
};

/**
 * Get the Display Transfer Characteristic from a CTA data block.
 *
 * Returns NULL if the data block tag is not
 * DI_CTA_DATA_BLOCK_VESA_DISPLAY_TRANSFER_CHARACTERISTIC.
 *
 * Upstream is not aware of any EDID blob containing a Display Transfer
 * Characteristic data block.
 * If such a blob is found, please share it with upstream!
 */
const struct di_cta_vesa_transfer_characteristics *
di_cta_data_block_get_vesa_transfer_characteristics(const struct di_cta_data_block *block);

/**
 * CTA YCbCr 4:2:0 Capability Map block, defined in section 7.5.11.
 */
struct di_cta_ycbcr420_cap_map;

/**
 * Returns true if the SVD in regular Video Data Blocks at index `svd_index`
 * supports YCbCr 4:2:0 subsampling.
 */
bool
di_cta_ycbcr420_cap_map_supported(const struct di_cta_ycbcr420_cap_map *cap_map,
				  size_t svd_index);

/**
 * Get the YCbCr 4:2:0 Capability Map from a CTA data block.
 *
 * Returns NULL if the data block tag is not DI_CTA_DATA_BLOCK_YCBCR420_CAP_MAP.
 */
const struct di_cta_ycbcr420_cap_map *
di_cta_data_block_get_ycbcr420_cap_map(const struct di_cta_data_block *block);

/**
 * InfoFrame types, defined in table 7.
 *
 * Note, the enum values don't match the specification.
 */
enum di_cta_infoframe_type {
	/* Auxiliary Video Information, defined in section 6.4. */
	DI_CTA_INFOFRAME_TYPE_AUXILIARY_VIDEO_INFORMATION,
	/* Source Product Description, defined in section 6.5. */
	DI_CTA_INFOFRAME_TYPE_SOURCE_PRODUCT_DESCRIPTION,
	/* Audio, defined in section 6.6. */
	DI_CTA_INFOFRAME_TYPE_AUDIO,
	/* MPEG Source, defined in section 6.7. */
	DI_CTA_INFOFRAME_TYPE_MPEG_SOURCE,
	/* NTSC VBI, defined in section 6.8. */
	DI_CTA_INFOFRAME_TYPE_NTSC_VBI,
	/* Dynamic Range and Mastering, defined in section 6.9. */
	DI_CTA_INFOFRAME_TYPE_DYNAMIC_RANGE_AND_MASTERING,
};

/**
 * CTA InfoFrame descriptor, defined in section 7.5.9.
 */
struct di_cta_infoframe_descriptor {
	/* Type of InfoFrame */
	enum di_cta_infoframe_type type;
};

/**
 * CTA InfoFrame processing, defined in section 7.5.9.
 */
struct di_cta_infoframe_block {
	/* Number of Vendor-specific InfoFrames that can be received
	 * simultaneously */
	int num_simultaneous_vsifs;
	/* Supported InfoFrames. The array is NULL-terminated. */
	const struct di_cta_infoframe_descriptor *const *infoframes;
};

/**
 * Get the InfoFrame information from a CTA data block.
 *
 * Returns NULL if the data block tag is not DI_CTA_DATA_BLOCK_INFOFRAME.
 */
const struct di_cta_infoframe_block *
di_cta_data_block_get_infoframe(const struct di_cta_data_block *block);

/**
 * Get a list of EDID detailed timing definitions.
 *
 * The returned array is NULL-terminated.
 */
const struct di_edid_detailed_timing_def *const *
di_edid_cta_get_detailed_timing_defs(const struct di_edid_cta *cta);

#endif
