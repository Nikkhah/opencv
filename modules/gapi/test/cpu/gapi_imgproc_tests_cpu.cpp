// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.
//
// Copyright (C) 2018 Intel Corporation


#include "../test_precomp.hpp"

#include "../common/gapi_imgproc_tests.hpp"
#include "opencv2/gapi/cpu/imgproc.hpp"

#define IMGPROC_CPU cv::gapi::imgproc::cpu::kernels()

namespace opencv_test
{

INSTANTIATE_TEST_CASE_P(Filter2DTestCPU, Filter2DTest,
                        Combine(Values(CV_8UC1, CV_8UC3, CV_16UC1, CV_16SC1, CV_32FC1),
                                Values(3, 4, 5, 7),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480),
                                       cv::Size(128, 128)),
                                Values(cv::BORDER_DEFAULT),
                                Values(-1, CV_32F),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(BoxFilterTestCPU, BoxFilterTest,
                        Combine(Values(CV_8UC1, CV_8UC3, CV_16UC1, CV_16SC1, CV_32FC1),
                                Values(3,5),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(cv::BORDER_DEFAULT),
                                Values(-1, CV_32F),
                                Values(0.0),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(SepFilterTestCPU_8U, SepFilterTest,
                        Combine(Values(CV_8UC1, CV_8UC3),
                                Values(3),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(-1, CV_16S, CV_32F),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(SepFilterTestCPU_other, SepFilterTest,
                        Combine(Values(CV_16UC1, CV_16SC1, CV_32FC1),
                                Values(3),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(-1, CV_32F),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(BlurTestCPU, BlurTest,
                        Combine(Values(CV_8UC1, CV_8UC3, CV_16UC1, CV_16SC1, CV_32FC1),
                                Values(3,5),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(cv::BORDER_DEFAULT),
                                Values(0.0),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(gaussBlurTestCPU, GaussianBlurTest,
                        Combine(Values(CV_8UC1, CV_8UC3, CV_16UC1, CV_16SC1, CV_32FC1),
                                Values(3, 5),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(MedianBlurTestCPU, MedianBlurTest,
                        Combine(Values(CV_8UC1, CV_8UC3, CV_16UC1, CV_16SC1, CV_32FC1),
                                Values(3, 5),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(ErodeTestCPU, ErodeTest,
                        Combine(Values(CV_8UC1, CV_8UC3, CV_16UC1, CV_16SC1, CV_32FC1),
                                Values(3, 5),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(cv::MorphShapes::MORPH_RECT,
                                       cv::MorphShapes::MORPH_CROSS,
                                       cv::MorphShapes::MORPH_ELLIPSE),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(Erode3x3TestCPU, Erode3x3Test,
                        Combine(Values(CV_8UC1, CV_8UC3, CV_16UC1, CV_16SC1, CV_32FC1),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(1,2,4),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(DilateTestCPU, DilateTest,
                        Combine(Values(CV_8UC1, CV_8UC3, CV_16UC1, CV_16SC1, CV_32FC1),
                                Values(3, 5),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(cv::MorphShapes::MORPH_RECT,
                                       cv::MorphShapes::MORPH_CROSS,
                                       cv::MorphShapes::MORPH_ELLIPSE),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(Dilate3x3TestCPU, Dilate3x3Test,
                        Combine(Values(CV_8UC1, CV_8UC3, CV_16UC1, CV_16SC1, CV_32FC1),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(1,2,4),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(SobelTestCPU, SobelTest,
                        Combine(Values(CV_8UC1, CV_8UC3, CV_16UC1, CV_16SC1, CV_32FC1),
                                Values(3, 5),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(-1, CV_32F),
                                Values(0, 1),
                                Values(1, 2),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(EqHistTestCPU, EqHistTest,
                        Combine(Values(cv::Size(1280, 720),
                                cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(CannyTestCPU, CannyTest,
                        Combine(Values(CV_8UC1, CV_8UC3),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(3.0, 120.0),
                                Values(125.0, 240.0),
                                Values(3, 5),
                                testing::Bool(),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(RGB2GrayTestCPU, RGB2GrayTest,
                        Combine(Values(cv::Size(1280, 720),
                                cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(BGR2GrayTestCPU, BGR2GrayTest,
                        Combine(Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(RGB2YUVTestCPU, RGB2YUVTest,
                        Combine(Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(YUV2RGBTestCPU, YUV2RGBTest,
                        Combine(Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(RGB2LabTestCPU, RGB2LabTest,
                        Combine(Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(BGR2LUVTestCPU, BGR2LUVTest,
                        Combine(Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(LUV2BGRTestCPU, LUV2BGRTest,
                        Combine(Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(BGR2YUVTestCPU, BGR2YUVTest,
                        Combine(Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

INSTANTIATE_TEST_CASE_P(YUV2BGRTestCPU, YUV2BGRTest,
                        Combine(Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
/*init output matrices or not*/ testing::Bool(),
                                Values(cv::compile_args(IMGPROC_CPU))));

} // opencv_test
