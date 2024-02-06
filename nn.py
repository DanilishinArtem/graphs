import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt

class generator:
    def __init__(self, N):
        self.x = np.random.rand(N)
        self.y = 3 * (self.x * self.x * self.x) + (self.x * self.x) + 0.5

gen = generator(100)
plt.plot(gen.x, label="x")
plt.plot(gen.y, label="y")
plt.legend()
plt.show()


# Define the number of inputs and outputs
# input_size = 10
# output_size = 5

# # Define the input and output placeholders
# inputs = tf.placeholder(tf.float32, shape=(None, input_size))
# targets = tf.placeholder(tf.float32, shape=(None, output_size))

# # Define the first layer
# hidden_layer_size = 50
# hidden_weights = tf.Variable(tf.random_normal([input_size, hidden_layer_size]))
# hidden_biases = tf.Variable(tf.random_normal([hidden_layer_size]))
# hidden_outputs = tf.nn.relu(tf.matmul(inputs, hidden_weights) + hidden_biases)

# # Define the second layer
# output_weights = tf.Variable(tf.random_normal([hidden_layer_size, output_size]))
# output_biases = tf.Variable(tf.random_normal([output_size]))
# outputs = tf.matmul(hidden_outputs, output_weights) + output_biases