#ifndef FORESTRYCPP_TREESPLIT_H
#define FORESTRYCPP_TREESPLIT_H

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include "forestryTree.h"
#include "DataFrame.h"
#include "RFNode.h"
#include "utils.h"
#include <armadillo>

double calculateRSS(
        DataFrame* trainingData,
        std::vector<size_t>* splittingSampleIndex,
        double overfitPenalty,
        std::mt19937_64& random_number_generator
);

void updateBestSplit(
        double* bestSplitLossAll,
        double* bestSplitValueAll,
        size_t* bestSplitFeatureAll,
        size_t* bestSplitCountAll,
        double currentSplitLoss,
        double currentSplitValue,
        size_t currentFeature,
        size_t bestSplitTableIndex,
        std::mt19937_64& random_number_generator
);

void updateBestSplitImpute(
        double* bestSplitLossAll,
        double* bestSplitValueAll,
        size_t* bestSplitFeatureAll,
        size_t* bestSplitCountAll,
        int* bestSplitNaDirectionAll,
        double currentSplitLoss,
        double currentSplitValue,
        size_t currentFeature,
        size_t bestSplitTableIndex,
        int currentSplitNaDirection,
        std::mt19937_64& random_number_generator
);

void updateBestSplitTrinary(
        double* bestSplitLossAll,
        double* bestSplitValueAll,
        size_t* bestSplitFeatureAll,
        size_t* bestSplitCountAll,
        int* bestSplitNaDirectionAll,
        std::vector<double>* bestSplitLeftWts,
        std::vector<double>* bestSplitRightWts,
        double currentSplitLoss,
        double currentSplitValue,
        size_t currentFeature,
        size_t bestSplitTableIndex,
        int currentSplitNaDirection,
        std::vector<double> currentSplitLeftWts,
        std::vector<double> currentSplitRightWts,
        std::mt19937_64& random_number_generator
);

void updateBestSplitS(
        arma::Mat<double> &bestSplitSL,
        arma::Mat<double> &bestSplitSR,
        const arma::Mat<double> &sTotal,
        DataFrame* trainingData,
        std::vector<size_t>* splittingSampleIndex,
        size_t bestSplitFeature,
        double bestSplitValue
);

void updateBestSplitG(
        arma::Mat<double> &bestSplitGL,
        arma::Mat<double> &bestSplitGR,
        const arma::Mat<double> &gTotal,
        DataFrame* trainingData,
        std::vector<size_t>* splittingSampleIndex,
        size_t bestSplitFeature,
        double bestSplitValue
);

void updateAArmadillo(
        arma::Mat<double>& a_k,
        arma::Mat<double>& new_x,
        bool leftNode
);

void updateSkArmadillo(
        arma::Mat<double>& s_k,
        arma::Mat<double>& next,
        double next_y,
        bool left
);

double computeRSSArmadillo(
        arma::Mat<double>& A_r,
        arma::Mat<double>& A_l,
        arma::Mat<double>& S_r,
        arma::Mat<double>& S_l,
        arma::Mat<double>& G_r,
        arma::Mat<double>& G_l
);

void updateRSSComponents(
        DataFrame* trainingData,
        size_t nextIndex,
        arma::Mat<double>& aLeft,
        arma::Mat<double>& aRight,
        arma::Mat<double>& sLeft,
        arma::Mat<double>& sRight,
        arma::Mat<double>& gLeft,
        arma::Mat<double>& gRight,
        arma::Mat<double>& crossingObservation,
        arma::Mat<double>& obOuter
);

void initializeRSSComponents(
        DataFrame* trainingData,
        size_t index,
        size_t numLinearFeatures,
        double overfitPenalty,
        const arma::Mat<double>& gTotal,
        const arma::Mat<double>& sTotal,
        arma::Mat<double>& aLeft,
        arma::Mat<double>& aRight,
        arma::Mat<double>& sLeft,
        arma::Mat<double>& sRight,
        arma::Mat<double>& gLeft,
        arma::Mat<double>& gRight,
        arma::Mat<double>& crossingObservation
);

double calcMuBarVar(
        // Calculates proxy for MSE of potential split
        double leftSum, size_t leftCount,
        double totalSum, size_t totalCount
);

void findBestSplitRidgeCategorical(
        std::vector<size_t>* averagingSampleIndex,
        std::vector<size_t>* splittingSampleIndex,
        size_t bestSplitTableIndex,
        size_t currentFeature,
        double* bestSplitLossAll,
        double* bestSplitValueAll,
        size_t* bestSplitFeatureAll,
        size_t* bestSplitCountAll,
        DataFrame* trainingData,
        size_t splitNodeSize,
        size_t averageNodeSize,
        std::mt19937_64& random_number_generator,
        double overfitPenalty,
        std::shared_ptr< arma::Mat<double> > gtotal,
        std::shared_ptr< arma::Mat<double> > stotal
);

void findBestSplitValueCategorical(
        std::vector<size_t>* averagingSampleIndex,
        std::vector<size_t>* splittingSampleIndex,
        size_t bestSplitTableIndex,
        size_t currentFeature,
        double* bestSplitLossAll,
        double* bestSplitValueAll,
        size_t* bestSplitFeatureAll,
        size_t* bestSplitCountAll,
        DataFrame* trainingData,
        size_t splitNodeSize,
        size_t averageNodeSize,
        std::mt19937_64& random_number_generator,
        size_t maxObs
);

void findBestSplitRidge(
        std::vector<size_t>* averagingSampleIndex,
        std::vector<size_t>* splittingSampleIndex,
        size_t bestSplitTableIndex,
        size_t currentFeature,
        double* bestSplitLossAll,
        double* bestSplitValueAll,
        size_t* bestSplitFeatureAll,
        size_t* bestSplitCountAll,
        DataFrame* trainingData,
        size_t splitNodeSize,
        size_t averageNodeSize,
        std::mt19937_64& random_number_generator,
        bool splitMiddle,
        size_t maxObs,
        double overfitPenalty,
        std::shared_ptr< arma::Mat<double> > gtotal,
        std::shared_ptr< arma::Mat<double> > stotal
);

void findBestSplitValueNonCategorical(
        std::vector<size_t>* averagingSampleIndex,
        std::vector<size_t>* splittingSampleIndex,
        size_t bestSplitTableIndex,
        size_t currentFeature,
        double* bestSplitLossAll,
        double* bestSplitValueAll,
        size_t* bestSplitFeatureAll,
        size_t* bestSplitCountAll,
        DataFrame* trainingData,
        size_t splitNodeSize,
        size_t averageNodeSize,
        std::mt19937_64& random_number_generator,
        bool splitMiddle,
        size_t maxObs,
        bool monotone_splits,
        monotonic_info monotone_details
);

void findBestSplitImpute(
        std::vector<size_t>* averagingSampleIndex,
        std::vector<size_t>* splittingSampleIndex,
        size_t bestSplitTableIndex,
        size_t currentFeature,
        double* bestSplitLossAll,
        double* bestSplitValueAll,
        size_t* bestSplitFeatureAll,
        size_t* bestSplitCountAll,
        int* bestSplitNaDirectionAll,
        DataFrame* trainingData,
        size_t splitNodeSize,
        size_t averageNodeSize,
        std::mt19937_64& random_number_generator,
        bool splitMiddle,
        size_t maxObs,
        bool monotone_splits,
        monotonic_info monotone_details
);

void findBestSplitImputeCategorical(
        std::vector<size_t>* averagingSampleIndex,
        std::vector<size_t>* splittingSampleIndex,
        size_t bestSplitTableIndex,
        size_t currentFeature,
        double* bestSplitLossAll,
        double* bestSplitValueAll,
        size_t* bestSplitFeatureAll,
        size_t* bestSplitCountAll,
        int* bestSplitNaDirectionAll,
        DataFrame* trainingData,
        size_t splitNodeSize,
        size_t averageNodeSize,
        std::mt19937_64& random_number_generator,
        size_t maxObs
);

void findBestSplitSymmetricOuter(
        std::vector<size_t>* averagingSampleIndex,
        std::vector<size_t>* splittingSampleIndex,
        size_t bestSplitTableIndex,
        size_t currentFeature,
        double* bestSplitLossAll,
        double* bestSplitValueAll,
        size_t* bestSplitFeatureAll,
        size_t* bestSplitCountAll,
        int* bestSplitNaDirectionAll,
        std::vector<double>* bestSplitLeftWtsAll,
        std::vector<double>* bestSplitRightWtsAll,
        DataFrame* trainingData,
        size_t splitNodeSize,
        size_t averageNodeSize,
        std::mt19937_64& random_number_generator,
        bool splitMiddle,
        size_t maxObs,
        bool monotone_splits,
        monotonic_info monotone_details,
        symmetric_info symmetric_details
);

double calcSymmetricLossVectorized(
        std::vector<double> SumsLeft,
        std::vector<double> SumsRight,
        std::vector<double> WtsLeft,
        std::vector<double> WtsRight,
        std::vector<size_t> CtsLeft,
        std::vector<size_t> CtsRight
);

double calcSymmetricLoss(
        double leftSum,
        double midSum,
        double rightSum,
        size_t nLeft,
        size_t nRight,
        size_t nMid,
        double leftWeight,
        double rightWeight,
        double midWeight
);

double calcSymmetricLossOuter(
        double leftPositiveSum,
        double leftNegativeSum,
        double rightPositiveSum,
        double rightNegativeSum,
        size_t leftPositiveCount,
        size_t leftNegativeCount,
        size_t rightPositiveCount,
        size_t rightNegativeCount,
        double leftPositiveWeight,
        double leftNegativeWeight,
        double rightPositiveWeight,
        double rightNegativeWeight
);

void updatePartitionWeights(
        double leftMean,
        double midMean,
        double rightMean,
        size_t nLeft,
        size_t nRight,
        size_t nMid,
        double &leftWeight,
        double &rightWeight,
        double &midWeight
);

void updatePartitionWeightsOuter(
        double negativeParentWeight,
        double positiveParentWeight,
        size_t nLP,
        size_t nRP,
        size_t nLN,
        size_t nRN,
        double uLP,
        double uRP,
        double uLN,
        double uRN,
        double &wLP,
        double &wRP,
        double &wLN,
        double &wRN
);

void updatePartitionWeightsSingle(
        double parentWeight,
        size_t nL,
        size_t nR,
        double uL,
        double uR,
        double &wL,
        double &wR
);

void determineBestSplit(
        size_t &bestSplitFeature,
        double &bestSplitValue,
        double &bestSplitLoss,
        int &bestSplitNaDir,
        std::vector<double> &bestSplitLeftWts,
        std::vector<double> &bestSplitRightWts,
        size_t mtry,
        double* bestSplitLossAll,
        double* bestSplitValueAll,
        size_t* bestSplitFeatureAll,
        size_t* bestSplitCountAll,
        int* bestSplitNaDirectionAll,
        std::vector<double>* bestSplitLeftWtsAll,
        std::vector<double>* bestSplitRightWtsAll,
        std::mt19937_64& random_number_generator
);

bool acceptMonotoneSplit(
    monotonic_info &monotone_details,
    size_t currentFeature,
    double leftPartitionMean,
    double rightPartitionMean
);

bool acceptMonotoneTrinarySplit(
        monotonic_info &monotone_details,
        size_t currentFeature,
        double leftPartitionMean,
        double rightPartitionMean,
        double centerPartitionMean
);

bool acceptMonotoneSplitSingle(
        monotonic_info &monotone_details,
        std::vector<size_t> symmetricFeatures,
        size_t currentFeature,
        double Lweight,
        double Rweight,
        size_t symmetric_idx,
        double upper_bound,
        double lower_bound
);

bool acceptMonotoneOuterSplit(
        monotonic_info &monotone_details,
        size_t currentFeature,
        double LPMean,
        double RPMean,
        double LNMean,
        double RNMean
);

int calculateNaDirection(
        double naMean,
        double left,
        double center,
        double right
);

int calculateNaDirectionOuter(
        double naMean,
        double LP,
        double LN,
        double RP,
        double RN
);

double calculateMonotonicBound(
    double node_mean,
    monotonic_info& monotone_details
);

double calculateMonotonicBoundSymmetric(
        double node_mean,
        double lower_bound,
        double upper_bound
);

void getSplitCounts(
        DataFrame* trainingData,
        std::vector<size_t>* averagingSampleIndex,
        size_t splitFeature,
        double splitValue,
        size_t &nLP,
        size_t &nRP,
        size_t &nLN,
        size_t &nRN,
        double &sLP,
        double &sRP,
        double &sLN,
        double &sRN
);

#endif //FORESTRYCPP_TREESPLIT_H
