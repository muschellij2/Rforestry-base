# pylint: disable=redefined-outer-name

import numpy as np
import pytest
from helpers import get_data

from Rforestry import RandomForest


@pytest.fixture
def forest():
    forest = RandomForest(
        ntree=500,
        replace=True,
        sample_fraction=0.8,
        mtry=3,
        nodesize_strict_spl=5,
        splitrule="variance",
        splitratio=1,
        nodesize_strict_avg=5,
        seed=2,
        oob_honest=True,
    )

    X, y = get_data()

    forest.fit(X, y)
    return forest


def test_get_parameters(forest):
    assert forest.get_parameters()
    assert forest.get_parameters()["ntree"] == 500
    assert forest.get_parameters()["double_bootstrap"]
    assert len(forest.get_parameters().keys()) == 27


def test_set_parameters(forest):
    X, y = get_data()

    forest.set_parameters(ntree=1000, max_depth=5, seed=1729)
    assert forest.get_parameters()["ntree"] == 1000
    assert forest.get_parameters()["max_depth"] == 5
    assert forest.get_parameters()["seed"] == 1729

    forest.fit(X, y)
    predictions_1 = forest.predict(X)

    forest.set_parameters(seed=1)
    assert forest.get_parameters()["ntree"] == 1000
    assert forest.get_parameters()["max_depth"] == 5
    assert forest.get_parameters()["seed"] == 1

    forest.fit(X, y)
    predictions_2 = forest.predict(X)

    assert not np.array_equal(predictions_1, predictions_2)
