<template lang="html">
   <div class="card">
      <h4>Week {{ number + 1 }}</h4>
      <p>{{ meta.description }}</p>
      <router-link :to="{ name: 'Lab', params: { week: this.link} }">More</router-link>
   </div>
</template>

<script>
export default {
   props: {
      link: String,
      meta: Object,
      number: Number
   }
}
</script>

<style lang="less" scoped>
@import '../assets/colors.less';
.card {
   margin: 20px 0px 20px 20px;
   width: 150px;
   display: flex;
   height: 150px;
   flex-direction: column;
   align-items: center;
   justify-content: center;
   border-left: 4px solid @accent;
   * {
      padding: 10px;
   }
}



</style>
