import re

import numpy as np
import pytest
from helpers import get_data

from Rforestry import RandomForest


def test_fit():

    forest = RandomForest()

    X, y = get_data()

    with pytest.raises(ValueError, match="The dimension of input dataset x doesn't match the output y."):
        forest.fit(X, y.drop(0))

    with pytest.raises(ValueError, match="y contains missing data."):
        forest.fit(X, y.replace(0, np.NaN))

    with pytest.raises(
        TypeError,
        match=re.escape(
            (
                "fit() takes 3 positional arguments but 4 positional arguments "
                "(and 6 keyword-only arguments) were given"
            )
        ),
    ):
        forest.fit(X, y, 23)

    with pytest.raises(ValueError, match="monotonic_constraints must have the size of x"):
        forest.fit(X, y, monotonic_constraints=[0, 2, 3])

    monotonic_constraints = np.array([0] * X.shape[1])
    monotonic_constraints[0] = 2
    with pytest.raises(ValueError, match="monotonic_constraints must be either 1, 0, or -1"):
        forest.fit(X, y, monotonic_constraints=monotonic_constraints)

    forest.set_parameters(linear=True)
    monotonic_constraints = np.array([0] * X.shape[1])
    monotonic_constraints[0] = 1
    with pytest.raises(ValueError, match="Cannot use linear splitting with monotonic_constraints"):
        forest.fit(X, y, monotonic_constraints=monotonic_constraints)

    observation_weights = np.array([0] * X.shape[0])
    forest.set_parameters(replace=True)
    with pytest.raises(ValueError, match="There must be at least one non-zero weight in observation_weights"):
        forest.fit(X, y, observation_weights=observation_weights)

    observation_weights = np.array([1] * X.shape[0])
    with pytest.raises(ValueError, match=re.escape("observation_weights must have length len(x)")):
        forest.fit(X, y, observation_weights=np.delete(observation_weights, 0))

    observation_weights[0] = -2
    with pytest.raises(ValueError, match="The entries in observation_weights must be non negative"):
        forest.fit(X, y, observation_weights=observation_weights)

    lin_feats = np.array([0] * X.shape[1])
    lin_feats[0] = -1
    with pytest.raises(
        ValueError, match=re.escape("lin_feats must contain positive integers less than len(x.columns).")
    ):
        forest.fit(X, y, lin_feats=lin_feats)

    lin_feats = np.array([0] * X.shape[1])
    lin_feats[0] = X.shape[1] + 1
    with pytest.raises(
        ValueError, match=re.escape("lin_feats must contain positive integers less than len(x.columns).")
    ):
        forest.fit(X, y, lin_feats=lin_feats)

    forest.set_parameters(linear=True)
    with pytest.raises(
        ValueError,
        match=(
            "Symmetric forests cannot be combined with linear aggregation. "
            "Please set either symmetric = False or linear = False"
        ),
    ):
        forest.fit(X, y, symmetric=[0, 1, 2, 3])


test_fit()
