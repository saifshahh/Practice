def is_valid(assignment, var, value, constraints):
    """Check if assigning 'value' to 'var' breaks any constraint."""
    for neighbor in constraints[var]:
        if neighbor in assignment and assignment[neighbor] == value:
            return False
    return True

def backtrack(assignment, variables, domains, constraints):
    """Backtracking algorithm to solve the CSP."""
    if len(assignment) == len(variables):
        return assignment  # All variables assigned

    var = [v for v in variables if v not in assignment][0]

    for value in domains[var]:
        if is_valid(assignment, var, value, constraints):
            assignment[var] = value
            result = backtrack(assignment, variables, domains, constraints)
            if result:
                return result
            del assignment[var]  # Backtrack

    return None

# Problem Setup: Map Coloring of Australia
variables = ['WA', 'NT', 'SA', 'Q', 'NSW', 'V', 'T']
domains = {var: ['Red', 'Green', 'Blue'] for var in variables}
constraints = {
    'WA': ['NT', 'SA'],
    'NT': ['WA', 'SA', 'Q'],
    'SA': ['WA', 'NT', 'Q', 'NSW', 'V'],
    'Q': ['NT', 'SA', 'NSW'],
    'NSW': ['SA', 'Q', 'V'],
    'V': ['SA', 'NSW'],
    'T': []
}

solution = backtrack({}, variables, domains, constraints)
print("CSP Solution:", solution)
