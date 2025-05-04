from pgmpy.models import BayesianModel
from pgmpy.factors.discrete import TabularCPD
from pgmpy.inference import VariableElimination

# 1. Define network structure
model = BayesianModel([('Rain', 'Traffic'), ('Accident', 'Traffic')])

# 2. Define CPDs (probability tables)
cpd_rain = TabularCPD('Rain', 2, [[0.7], [0.3]])  # 0 = No rain, 1 = Rain
cpd_accident = TabularCPD('Accident', 2, [[0.9], [0.1]])  # 0 = No accident, 1 = Accident

# CPT for Traffic: P(Traffic | Rain, Accident)
cpd_traffic = TabularCPD('Traffic', 2,
                         [[0.9, 0.6, 0.7, 0.1],   # P(Traffic=0 | Rain, Accident)
                          [0.1, 0.4, 0.3, 0.9]],  # P(Traffic=1 | Rain, Accident)
                         evidence=['Rain', 'Accident'],
                         evidence_card=[2, 2])

# 3. Add CPDs to the model
model.add_cpds(cpd_rain, cpd_accident, cpd_traffic)

# 4. Inference
inference = VariableElimination(model)
result = inference.query(variables=['Traffic'], evidence={'Rain': 1})

print(result)
